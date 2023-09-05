class Solution {
public:
    
    int f(int i, int j, vector<vector<int>> &a, vector<vector<int>> &dp){
        
        if(i >= a.size() || j >= a[0].size()) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(i == a.size()-1 and j == a[0].size()-1){
            if(a[i][j] <= 0) return -a[i][j] + 1;
            else return 1;
        }
        int down = f(i+1, j, a, dp);
        int right = f(i, j+1, a, dp);
        int ans = min(down, right) - a[i][j];
        
        if(ans <= 0) return dp[i][j] =  1;
        else return dp[i][j] =  ans;
        
    }
    
    int calculateMinimumHP(vector<vector<int>>& a) {
        
        vector<vector<int>> dp(a.size(), vector<int>(a[0].size(), -1));
        return f(0, 0, a, dp);
    }
};