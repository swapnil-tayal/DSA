class Solution {
public:
    
    int f(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp){
        
        if(i == triangle.size()-1){
            return triangle[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        int down = f(i+1, j, triangle, dp);
        int downL = f(i+1, j+1, triangle, dp);
        return dp[i][j] = triangle[i][j] + min(down, downL);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
//         for(int j=0; j<n; j++){
//             dp[n-1][j] = triangle[n-1][j];
//         }
        
//         for(int i=n-2; i>=0; i--){
//             for(int j=i; j>=0; j--){
                
//                 int down = dp[i+1][j];
//                 int downL = dp[i+1][j+1];
//                 dp[i][j] = triangle[i][j] + min(down, downL);                
//             }
//         }
        
        return f(0, 0, triangle, dp);
    }
};