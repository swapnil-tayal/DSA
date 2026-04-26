class Solution {
    int n;
    int m;
public:

    int f(int i, int j, int pari, int parj, char ch, vector<vector<char>> &grid, vector<vector<int>> &vis){

        int row[] = {-1,1,0,0};
        int col[] = {0,0,-1,1};
        vis[i][j] = true;
    
        for(int k=0; k<4; k++){

            int newx = i + row[k];
            int newy = j + col[k];

            if(newx < 0 || newy < 0 || newx >= n || newy >= m) continue;
            if(grid[newx][newy] != ch || (newx == pari && newy == parj)) continue;
            if(vis[newx][newy] == 1) return true;
            if(f(newx, newy, i, j, ch, grid, vis)) return true;
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        
        this->n = grid.size();
        this->m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] == 1) continue;
                if(f(i, j, -1, -1, grid[i][j], grid, vis)) return true;
            }
        }
        return false;
    }
};