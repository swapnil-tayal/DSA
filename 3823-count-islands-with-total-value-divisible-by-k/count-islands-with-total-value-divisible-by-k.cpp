class Solution {
    vector<vector<int>> vis;
    vector<int> row, col;
    int n, m;
public:

    void dfs(int i, int j, vector<vector<int>> &grid, long long &sum){

        vis[i][j] = 1;
        sum += grid[i][j];
        for(int k=0; k<4; k++){
            
            int newi = row[k] + i;
            int newj = col[k] + j;
            if(newi >= 0 and newj >= 0 and newi < n and newj < m and grid[newi][newj] > 0 && vis[newi][newj] == 0){
                dfs(newi, newj, grid, sum);
            }
        }
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        
        n = grid.size();
        m = grid[0].size();
        vis.assign(n, vector<int>(m, 0));
        row = {0,0,-1,1};
        col = {1,-1,0,0};
        int cnt = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] || grid[i][j] == 0) continue;
                long long sum = 0;
                dfs(i, j, grid, sum);
                if(sum % k == 0) cnt++;
            }
        }
        return cnt;

    }
};