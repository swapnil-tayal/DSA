class Solution {
public:

    vector<vector<int>> prefixSum2D(vector<vector<int>> &arr) {
    
        int n = arr.size();
        int m = arr[0].size();    
        vector<vector<int>> prefix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefix[i][j] = arr[i][j];
                if (i > 0) {
                    prefix[i][j] += prefix[i - 1][j];
                }
                if (j > 0) {
                    prefix[i][j] += prefix[i][j - 1];
                }
                if (i > 0 && j > 0) {
                    prefix[i][j] -= prefix[i - 1][j - 1];
                }
            }
        }
        return prefix;
    }

    int countSubmatrices(vector<vector<int>>& grid, int k) {
        
        grid = prefixSum2D(grid);
        int cnt = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] <= k) cnt++;
            }
        }
        return cnt;
    }
};