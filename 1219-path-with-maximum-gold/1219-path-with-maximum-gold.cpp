class Solution {
    int ans;
    vector<int> row;
    vector<int> col;
    int n, m;
public:
    
    void f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis, int &sum){
        
        if(grid[i][j] == 0) return;
        sum += grid[i][j];
        ans = max(ans, sum);
        for(int k=0; k<4; k++){
            
            int newx = i + row[k];
            int newy = j + col[k];
            if(newx < n and newx >= 0 and newy >= 0 and newy < m and vis[newx][newy] == 0){
                
                vis[newx][newy] = 1;
                f(newx, newy, grid, vis, sum);
                vis[newx][newy] = 0;
            }
        }
        sum -= grid[i][j];
        return;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        
        row = {1,0,-1,0};
        col = {0,1,0,-1};
        ans = 0;
        n = grid.size();
        m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                vector<vector<int>> vis(n, vector<int>(m, 0));
                vis[i][j] = 1;
                int sum = 0;
                f(i, j, grid, vis, sum);
            }
        }
        return ans;
    }
};