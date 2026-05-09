class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int d) {
        
        vector<vector<int>> a;
        int n = grid.size();
        int m = grid[0].size();

        for(int k=0; k<min(n, m)/2; k++){

            vector<int> t;
            for(int j=k; j<m-k-1; j++) t.push_back(grid[k][j]);
            // for(auto &i: t) cout<<i<<' ';
            // cout<<'\n';
            // t.pop_back();
            for(int i=k; i<n-k-1; i++) t.push_back(grid[i][m-k-1]);
            // for(auto &i: t) cout<<i<<' ';
            // cout<<'\n';
            // t.pop_back();
            for(int j=m-k-1; j>=k+1; j--) t.push_back(grid[n-k-1][j]);
            // for(auto &i: t) cout<<i<<' ';
            // cout<<'\n';
            // t.pop_back();
            for(int i=n-k-1; i>=k+1; i--) t.push_back(grid[i][k]);
            // for(auto &i: t) cout<<i<<' ';
            // cout<<'\n';
            // t.pop_back();
            // for(auto &i: t) cout<<i<<' ';
            // cout<<'\n';
            int newD = d % t.size();
            rotate(t.begin(), t.begin() + newD, t.end());
            // for(auto &i: t) cout<<i<<' ';
            // cout<<'\n';

            int ind = 0;

            for(int j=k; j<m-k-1; j++) grid[k][j] = t[ind++];
            // ind--;
            for(int i=k; i<n-k-1; i++) grid[i][m-k-1] = t[ind++];
            // ind--;
            for(int j=m-k-1; j>=k+1; j--) grid[n-k-1][j] = t[ind++];
            // ind--;
            for(int i=n-k-1; i>=k+1; i--) grid[i][k] = t[ind++];
            // ind--;

        }
        return grid;
    }
};