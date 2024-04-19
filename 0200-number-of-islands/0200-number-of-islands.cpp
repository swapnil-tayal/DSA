class Solution {
public:
    
    void f(int i, int j, vector<vector<char>> &grid){
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        q.push({ i, j });
        
        int row[] = {-1,0,1,0};
        int col[] = {0,-1,0,1};
        
        while(!q.empty()){
            
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int k=0; k<4; k++){
                
                int newx = x + row[k];
                int newy = y + col[k];
                if(newx >= 0 and newy >= 0 and newx < n and newy < m and grid[newx][newy] == '1'){
                    
                    grid[newx][newy] = '0';
                    q.push({ newx, newy });
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(grid[i][j] == '1'){
                    cnt++;
                    f(i, j, grid);
                }
            }
        }
        return cnt;
    }
};