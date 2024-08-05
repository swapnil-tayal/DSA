class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        
        int rows = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m/2; j++){
                if(grid[i][j] != grid[i][m-j-1]) rows++;
            }
        }
        int cols = 0;
        for(int j=0; j<m; j++){
            for(int i=0; i<n/2; i++){
                if(grid[i][j] != grid[n-i-1][j]) cols++;
            }
        }
        return min(rows, cols);
    }
};