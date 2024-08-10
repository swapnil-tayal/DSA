class Solution {
public:
    
    void makeGrid(vector<string> &grid, vector<vector<int>> &a){
        int n = grid.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                
                int x = i*3;
                int y = j*3;
                if(grid[i][j] == '/'){
                    
                    a[x][y] = 0;
                    a[x][y+1] = 0;
                    a[x][y+2] = 1;
                    a[x+1][y] = 0;
                    a[x+1][y+1] = 1;
                    a[x+1][y+2] = 0;
                    a[x+2][y] = 1;
                    a[x+2][y+1] = 0;
                    a[x+2][y+2] = 0;
                    
                }else if(grid[i][j] == ' '){
                    
                    a[x][y] = 0;
                    a[x][y+1] = 0;
                    a[x][y+2] = 0;
                    a[x+1][y] = 0;
                    a[x+1][y+1] = 0;
                    a[x+1][y+2] = 0;
                    a[x+2][y] = 0;
                    a[x+2][y+1] = 0;
                    a[x+2][y+2] = 0;
                    
                }else{
                    
                    a[x][y] = 1;
                    a[x][y+1] = 0;
                    a[x][y+2] = 0;
                    a[x+1][y] = 0;
                    a[x+1][y+1] = 1;
                    a[x+1][y+2] = 0;
                    a[x+2][y] = 0;
                    a[x+2][y+1] = 0;
                    a[x+2][y+2] = 1;
                    
                }
            }
        }
    }
    
    void dfs(vector<vector<int>> &arr, int i, int j){
        
        arr[i][j] = 1;
        int row[] = {-1, 1, 0, 0};
        int col[] = {0, 0, -1, 1};
        
        for(int k=0; k<4; k++){
            
            int newx = i + row[k];
            int newy = j + col[k];
            if(newx < 0 || newy < 0 || newx >= arr.size() || newy >= arr.size()) continue;
            if(arr[newx][newy] == 1) continue;
            dfs(arr, newx, newy);
        }
    }
    
    int regionsBySlashes(vector<string>& grid) {
        
        int n = grid.size();
        
        vector<vector<int>> a(n*3, vector<int>(n*3));
        
        makeGrid(grid, a);
        
        int cnt = 0;
        for(int i=0; i<3*n; i++){
            for(int j=0; j<3*n; j++){
                if(a[i][j] == 0){
                    dfs(a, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};