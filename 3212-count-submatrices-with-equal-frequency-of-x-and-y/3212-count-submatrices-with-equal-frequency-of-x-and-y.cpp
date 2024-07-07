class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> x(n, vector<int>(m, 0));
        vector<vector<int>> y(n, vector<int>(m, 0));
        
        x[0][0] = (grid[0][0] == 'X');
        y[0][0] = (grid[0][0] == 'Y');
        
        for(int i=1; i<m; i++){
            x[0][i] = x[0][i-1] + (grid[0][i]=='X');
            y[0][i] = y[0][i-1] + (grid[0][i]=='Y');
        }
        for(int j=1; j<n; j++){
            x[j][0] = x[j-1][0] + (grid[j][0]=='X');
            y[j][0] = y[j-1][0] + (grid[j][0]=='Y');
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                
                x[i][j] = x[i-1][j] + x[i][j-1] - x[i-1][j-1] + (grid[i][j]=='X');
                y[i][j] = y[i-1][j] + y[i][j-1] - y[i-1][j-1] + (grid[i][j]=='Y');
            }
        }
        // for(auto i: x){
        //     for(auto j: i) cout<<j<<' ';
        //     cout<<'\n';
        // }
        // for(auto i: y){
        //     for(auto j: i) cout<<j<<' ';
        //     cout<<'\n';
        // }
        
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(x[i][j] == y[i][j] and x[i][j] > 0) cnt++;
            }
        }
        return cnt;
    }
};