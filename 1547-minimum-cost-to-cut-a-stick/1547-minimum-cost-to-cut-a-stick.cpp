class Solution {
public:
    
    int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
        
        if(j-i <= 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 1e9;
        for(int k=i+1; k<j; k++){ 
            // cout<<1<<' ';
            int cost = (cuts[j] - cuts[i]) + f(i, k, cuts, dp) + f(k, j, cuts, dp);
            ans = min(ans, cost);
        }
        return dp[i][j] = ans;
    }
    
    int minCost(int n, vector<int>& cuts) {
        
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        n = cuts.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, n-1, cuts, dp);
    }
};