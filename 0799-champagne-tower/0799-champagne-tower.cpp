class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
    
        vector<vector<double>> grid;
        
        vector<double> temp = {(double)poured};
        grid.push_back(temp);
        
        for(int i=0; i<100; i++){
            
            int f = 0;
            vector<double> temp(i+2, 0);
            for(int j=0; j<=i; j++){
                
                if(grid[i][j] > 1){
                    
                    double x = grid[i][j]-1;
                    grid[i][j] = 1;
                    temp[j] += x/(2.0);
                    temp[j+1] += x/(2.0);
                    f = 1;
                }
            }
            grid.push_back(temp);
            if(f == 0) break; 
        }
        if(query_row >= grid.size()) return 0;
        return grid[query_row][query_glass];
    }
};