class Solution{
public:
    
    long long f(int src, int par, int pick, vector<int> adj[], vector<int> &values, vector<vector<long long>> &dp){
        
        long long ans1 = 0;
        long long ans2 = 0;
        int c = 0;
        if(dp[src][pick] != -1) return dp[src][pick];
        
        for(auto i: adj[src]){
            if(i == par) continue;
            c = 1;
            
            if(pick == 0){
                
                ans1 += f(i, src, 1, adj, values, dp);
                ans2 += f(i, src, 0, adj, values, dp);
            
            }else ans1 += f(i, src, 1, adj, values, dp);
        }
        
        if(c == 0){
            if(pick == 0) return dp[src][pick] = 0;
            else return dp[src][pick] = values[src];
        }
        
        if(pick == 0){
            return dp[src][pick] = max(ans1, ans2 + values[src]);
        }else{
            return dp[src][pick] = values[src] + ans1;
        }

    }
    
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        
        int n = values.size();
        vector<int> adj[n];
        
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return f(0, -1, 0, adj, values, dp);
    }
};