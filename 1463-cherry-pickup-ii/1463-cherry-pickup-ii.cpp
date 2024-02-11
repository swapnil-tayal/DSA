class Solution {
public:
    
    int f(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
        
        if(j1 < 0 || j1 >= grid[0].size() || j2 < 0 || j2 >= grid[0].size()){
            return -1e9;
        }
        if(i == grid.size()) return 0;
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        int sum = 0;
        if(j1 == j2) sum += grid[i][j1];
        else{
            sum += grid[i][j1];
            sum += grid[i][j2];
        }
        int ans = 0;
        ans = max(ans, f(i+1, j1, j2, grid, dp));
        ans = max(ans, f(i+1, j1+1, j2, grid, dp));
        ans = max(ans, f(i+1, j1, j2+1, grid, dp));
        ans = max(ans, f(i+1, j1+1, j2+1, grid, dp));
        ans = max(ans, f(i+1, j1-1, j2, grid, dp));
        ans = max(ans, f(i+1, j1, j2-1, grid, dp));
        ans = max(ans, f(i+1, j1-1, j2-1, grid, dp));
        ans = max(ans, f(i+1, j1-1, j2+1, grid, dp));
        ans = max(ans, f(i+1, j1+1, j2-1, grid, dp));
        return dp[i][j1][j2] = ans + sum;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return f(0, 0, m-1, grid, dp);
    }
};