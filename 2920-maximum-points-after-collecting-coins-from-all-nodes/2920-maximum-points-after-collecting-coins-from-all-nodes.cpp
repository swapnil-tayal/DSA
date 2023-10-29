class Solution{
public:
    int g(int x, int k){
        while(k > 0){
            x /= 2;
            k--;
        }
        return x;
    }
    
    int f(int src, int par, vector<int> adj[], vector<int> &coins, int k, int cnt, vector<vector<int>> &dp){
        
        int ans1 = 0;
        int ans2 = 0;
        int t = 0;
        if(dp[src][cnt] != -1) return dp[src][cnt];
        
        for(auto i: adj[src]){
            
            if(i == par) continue;
            t = 1;
            
            int first = f(i, src, adj, coins, k, min(15, cnt+1), dp);
            int second = f(i, src, adj, coins, k, cnt, dp);
            
            ans1 += first;
            ans2 += second;
        }
        int x = g(coins[src], cnt);
        return dp[src][cnt] = max(ans1 + x/2, ans2 + x-k);
    }
    
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        
        int n = edges.size() + 1;
        vector<int> adj[n];
        
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<vector<int>> dp(n, vector<int>(16, -1));
        return f(0, -1, adj, coins, k, 0, dp);
    }
};