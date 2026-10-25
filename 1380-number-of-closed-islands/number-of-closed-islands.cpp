class Solution {
    int n, m;
public:

    bool f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis){

        int row[] = {-1,0,0,1};
        int col[] = {0,-1,1,0};

        vis[i][j] = 1;
        bool ans = true;
        for(int k=0; k<4; k++){
            int newi = row[k] + i;
            int newj = col[k] + j;
            
            if(newi < 0 || newj < 0 || newi >= n || newj >= m) continue;
            if(newi == 0 || newj == 0 || newi == n-1 || newj == m-1){
                if(grid[newi][newj] == 0) ans = false;
                else continue;
            }
            if(vis[newi][newj]) continue;
            if(grid[newi][newj] == 0) ans = f(newi, newj, grid, vis) && ans;
        }
        return ans;
    }

    int closedIsland(vector<vector<int>>& grid) {
        
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(grid[i][j] == 0 and vis[i][j] == 0){
                    if(f(i, j, grid, vis)){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};