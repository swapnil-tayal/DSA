class Solution {
    int n, m;
    vector<vector<int>> dp;
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    
    int dfs(int i, int j, vector<vector<int>>& matrix) {
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 1;
        for(int k = 0; k < 4; k++) {
            int ni = i + dir[k][0];
            int nj = j + dir[k][1];
            if(ni >= 0 && nj >= 0 && ni < n && nj < m && matrix[ni][nj] > matrix[i][j]) {
                ans = max(ans, 1 + dfs(ni, nj, matrix));
            }
        }
        return dp[i][j] = ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        dp.resize(n, vector<int>(m, -1));
        int ans = 1;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j, matrix));
            }
        }
        return ans;
    }
};
