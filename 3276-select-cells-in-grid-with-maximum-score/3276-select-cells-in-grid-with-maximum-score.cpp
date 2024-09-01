class Solution {
    vector<int> temp;
public:
    
    int f(int i, vector<pair<int,int>> &a, int mask, vector<vector<int>> &dp){
        
        if(i == a.size()) return 0;
        if(dp[i][mask] != -1) return  dp[i][mask];
        
        int pick = 0;
        int npick = 0;
        
        if((mask >> a[i].second) % 2 == 0){
            
            int newMask = mask | (1 << a[i].second);
            
            int ind = lower_bound(temp.begin(), temp.end(), a[i].first) - temp.begin();
            if(ind == 0) ind = a.size();
            else ind = temp.size() - ind;
            
            pick = a[i].first + f(ind, a, newMask, dp);
        
        }
        npick = f(i+1, a, mask, dp);
        return dp[i][mask] = max(pick, npick);
    }
    
    int maxScore(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<pair<int,int>> a;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                a.push_back({ grid[i][j], i });
                temp.push_back(grid[i][j]);
            }
        }
        sort(temp.begin(), temp.end());
        sort(a.rbegin(), a.rend());
        vector<vector<int>> dp(a.size(), vector<int>(2000, -1));
        return f(0, a, 0, dp);
    }
};