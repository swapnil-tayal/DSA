class Solution {
public:
    
    int f(int i, int j, int n, vector<vector<int>> &triangle, vector<vector<int>> &dp){
        
        if(i == n-1){
            return triangle[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        int down = f(i+1, j, n, triangle, dp);
        int downL = f(i+1, j+1, n, triangle, dp);
        return dp[i][j] = triangle[i][j] + min(down, downL);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> ahead(n, 0), curr(n, 0);
             
        for(int j=0; j<n; j++){
            ahead[j] = triangle[n-1][j];
        }
        
        for(int i=n-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                
                int down = ahead[j];
                int downL = ahead[j+1];
                curr[j] = triangle[i][j] + min(down, downL);                
            }
            ahead = curr;
        }
        
        return ahead[0];
    }
};