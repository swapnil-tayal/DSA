class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        // if(poured >= 5050) return 1;
        
        vector<vector<double>> grid(101, vector<double>(100, 0));
        grid[0][0] = (double)poured;
        
        
        for(int i=0; i<100; i++){
            
            int f = 0;
            for(int j=0; j<=i; j++){
                
                if(grid[i][j] > 1){
                    
                    double x = grid[i][j]-1;
                    grid[i][j] = 1;
                    grid[i+1][j] += x/(2.0);
                    grid[i+1][j+1] += x/(2.0);
                    f = 1;
                }
            }
            if(f == 0) break; 
        }
        // for(int i=0; i<4; i++){
        //     for(int j=0; j<=i; j++) cout<<grid[i][j]<<' ';
        //     cout<<'\n';
        // }
        return grid[query_row][query_glass];
    }
};