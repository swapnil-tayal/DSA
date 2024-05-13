class Solution {
public:
    
    int matrixScore(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<n; i++){
            if(grid[i][0] == 1){
                for(int j=0; j<m; j++){
                    grid[i][j] = grid[i][j] == 1 ? 0 : 1;
                }
            }
        }
        for(int j=0; j<m; j++){
            int ones = 0;
            int zeros = 0;
            for(int i=0; i<n; i++){
                ones += grid[i][j] == 1;
                zeros += grid[i][j] == 0;
            }
            if(ones < zeros){
                for(int i=0; i<n; i++){
                    grid[i][j] = grid[i][j] == 1 ? 0 : 1;
                }
            }
        }
        
//         for(auto i: grid){
//             for(auto j: i) cout<<j<<' ';
//             cout<<'\n';
//         }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]) ans += pow(2, (m-j-1));
            }
        }
        return ans;
    }
};