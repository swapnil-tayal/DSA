class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int minr = 1e9;
        int maxr = 0;
        int minc = 1e9;
        int maxc = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0) continue;
                minr = min(minr, i);
                maxr = max(maxr, i);
                minc = min(minc, j);
                maxc = max(maxc, j);
            }
        }
        // cout<<minr<<' '<<maxr<<' '<<minc<<' '<<maxc<<'\n';
        int ans = (maxr - minr + 1) * (maxc - minc + 1);
        return ans;
    }
};