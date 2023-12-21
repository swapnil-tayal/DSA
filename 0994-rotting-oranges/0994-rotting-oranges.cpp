class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<vector<int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2) q.push({ i, j, 0 });
            }
        }
        
        int row[] = {-1,0,0,1};
        int col[] = {0,-1,1,0};
        int ans = 0;
        
        while(!q.empty()){
            
            int i = q.front()[0];
            int j = q.front()[1];
            int cnt = q.front()[2];
            ans = max(ans, cnt);
            q.pop();
            for(int k=0; k<4; k++){
                
                int newi = i + row[k];
                int newj = j + col[k];
                if(newi >= 0 and newj >= 0 and newi < n and newj < m and grid[newi][newj] == 1){
                    
                    grid[newi][newj] = 2;
                    q.push({ newi, newj, cnt+1 });
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) return -1; 
            }
        }
        return ans;
    }
};