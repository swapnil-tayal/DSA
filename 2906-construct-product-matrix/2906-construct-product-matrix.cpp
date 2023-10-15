class Solution {
    int n,m;
    vector<long long> preRow;
    vector<long long> sufRow;
    const int mod = 12345;
    
    void f(vector<vector<int>> &grid, vector<vector<long long>> &prefixRow, vector<vector<long long>> &sufixRow){
        for(int i=0; i<n; i++){
            
            long long pro = 1;
            for(int j=0; j<m; j++){
                pro = (pro * grid[i][j]) % mod;
            }
            if(i-1 < 0) preRow[i] = pro;
            else preRow[i] = (preRow[i-1] * pro) % mod;
        }
        for(int i=n-1; i>=0; i--){
            
            long long pro = 1;
            for(int j=0; j<m; j++){
                pro = (pro * grid[i][j]) % mod;
            }
            if(i+1 == n) sufRow[i] = pro;
            else sufRow[i] = (sufRow[i+1] * pro) % mod;
        }
        for(int i=0; i<n; i++){
            prefixRow[i][0] = grid[i][0];
            for(int j=1; j<m; j++){
                prefixRow[i][j] = (prefixRow[i][j-1] * grid[i][j]) % mod;
            }
        }
        for(int i=0; i<n; i++){
            sufixRow[i][m-1] = grid[i][m-1];
            for(int j=m-2; j>=0; j--){
                sufixRow[i][j] = (sufixRow[i][j+1] * grid[i][j]) % mod;
            }
        }
    }
    
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        
        n = grid.size();
        m = grid[0].size();
        preRow.resize(n);
        sufRow.resize(n);
        vector<vector<long long>> prefixRow(n, vector<long long>(m));
        vector<vector<long long>> sufixRow(n, vector<long long>(m));
        
        f(grid, prefixRow, sufixRow);
        
        // for(auto i: preRow) cout<<i<<' ';
        // cout<<'\n';
        // for(auto i: sufRow) cout<<i<<' ';
        // cout<<'\n';
        // for(auto i: prefixRow){
        //     for(auto j: i) cout<<j<<' ';
        //     cout<<'\n';
        // }
        // for(auto i: sufixRow){
        //     for(auto j: i) cout<<j<<' ';
        //     cout<<'\n';
        // }
        
        vector<vector<int>> ans(n, vector<int>(m, -1));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                long long pro = 1;
                if(i-1 >= 0) pro = (pro * preRow[i-1]) % mod;
                if(i+1 < n) pro = (pro * sufRow[i+1]) % mod;
                if(j-1 >= 0) pro = (pro * prefixRow[i][j-1]) % mod;
                if(j+1 < m) pro = (pro * sufixRow[i][j+1]) % mod;
                ans[i][j] = pro;
            }
        }
        return ans;
    }
};