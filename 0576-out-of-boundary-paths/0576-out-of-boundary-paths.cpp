class Solution {
public:
    
    int f(int i, int j, int maxMove, int n, int m, vector<vector<vector<int>>> &dp){
        
        if(i < 0 || j < 0 || i == n || j == m) return 1;
        if(maxMove == 0) return 0;
        if(dp[i][j][maxMove] != -1) return dp[i][j][maxMove];
        
        long long up = f(i-1, j, maxMove-1, n, m, dp);
        long long down = f(i+1, j, maxMove-1, n, m, dp);
        long long right = f(i, j+1, maxMove-1, n, m, dp);
        long long left = f(i, j-1, maxMove-1, n, m, dp);
        
        return dp[i][j][maxMove] = (long long)(up + down + right + left) % 1000000007;
    }
    
    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(maxMove+1, -1)));
        return f(startRow, startColumn, maxMove, n, m, dp);
    }
};