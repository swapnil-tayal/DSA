class Solution {
public:
    
    void f(int i, int j, vector<vector<char>> &grid){
        
        queue<pair<int,int>> q;
        q.push({ i, j });
        
        int row[] = {1,0,-1,0};
        int col[] = {0,1,0,-1};
        int n = grid.size();
        int m = grid[0].size();
        grid[i][j] = '0';

        while(!q.empty()){
            
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int k=0; k<4; k++){
                
                int newi = x + row[k];
                int newj = y + col[k];
                
                if(newi >=0 and newj >= 0 and newi < n and newj < m and grid[newi][newj] == '1'){
                    
                    grid[newi][newj] = '0';
                    q.push({ newi, newj });
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        
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