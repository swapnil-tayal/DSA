class Solution {
    int n, m;
public:

    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>> &grid){

        int row[] = {1, -1, 0, 0};
        int col[] = {0, 0, -1, 1};
        vis[i][j] = 1;

        for(int k=0; k<4; k++){

            int newi = row[k] + i;
            int newj = col[k] + j;

            if(newi >= 0 and newj >= 0 and newi<n and newj<m and grid[newi][newj] == '1' and vis[newi][newj] == 0){
                dfs(newi, newj, vis, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] || grid[i][j] == '0') continue;
                cnt++;
                dfs(i, j, vis, grid);
            }
        }
        return cnt;
    }
};