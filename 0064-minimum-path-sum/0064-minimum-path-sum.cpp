class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        dp[0][0] = grid[0][0];
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(i == 0 and j == 0) continue;
                int x = 1e9;
                if(i-1 >= 0) x = dp[i-1][j];
                if(j-1 >= 0) x = min(x, dp[i][j-1]);
                dp[i][j] = grid[i][j] + x;
            }
        }
        
        // for(auto i: dp){
        //     for(auto j: i) cout<<j<<' ';
        //     cout<<'\n';
        // }
        return dp[n-1][m-1];
    }
};