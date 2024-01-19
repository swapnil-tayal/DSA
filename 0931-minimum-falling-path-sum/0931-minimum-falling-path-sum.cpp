class Solution{
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int j=0; j<n; j++){
            dp[n-1][j] = matrix[n-1][j];
        }
        
        for(int i=n-2; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                
                int ans = 1e9;
                if(j+1 < n) ans = min(ans, matrix[i][j] + dp[i+1][j+1]);
                ans = min(ans, matrix[i][j] + dp[i+1][j]);
                if(j-1 >= 0) ans = min(ans, matrix[i][j] + dp[i+1][j-1]);
                
                dp[i][j] = ans;
            }
        }
        
        int ans = 1e9;
        for(int j=0; j<n; j++) ans = min(ans, dp[0][j]);
        return ans;
    }
};