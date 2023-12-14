class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<int> row(n);
        vector<int> col(m);
        
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=0; j<m; j++){
                cnt += grid[i][j];
            }
            row[i] = cnt;
        }
        for(int j=0; j<m; j++){
            int cnt = 0;
            for(int i=0; i<n; i++){
                cnt += grid[i][j];
            }
            col[j] = cnt;
        }
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                grid[i][j] = 2*row[i] + 2*col[j] - n - m;
            }
        }
        return grid;
    }
};