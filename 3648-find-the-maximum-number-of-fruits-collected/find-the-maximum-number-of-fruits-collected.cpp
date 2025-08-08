class Solution {
public:

    int f1(vector<vector<int>> &fruits, int i, int j, int n, vector<vector<int>> &dp){
        if(i == n-1 && j == n-2) return fruits[i][j];
        if(i == j || (i+j) < n-1 || i == n || j == n) return -1e9;
        if(dp[i][j] != -1) return dp[i][j];
        int w1 = f1(fruits, i+1, j+1, n, dp);
        int w2 = f1(fruits, i, j+1, n, dp);
        int w3 = f1(fruits, i-1, j+1, n, dp);
        return dp[i][j] = max(w1, max(w2, w3)) + fruits[i][j];
    }
    int f2(vector<vector<int>> &fruits, int i, int j, int n, vector<vector<int>> &dp){
        if(j == n-1 && i == n-2) return fruits[i][j];
        if(i == j || (i+j) < n-1 || i == n || j == n) return -1e9;
        if(dp[i][j] != -1) return dp[i][j];
        int w1 = f2(fruits, i+1, j+1, n, dp);
        int w2 = f2(fruits, i+1, j-1, n, dp);
        int w3 = f2(fruits, i+1, j, n, dp);
        return dp[i][j] = max(w1, max(w2, w3)) + fruits[i][j];
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        
        int n = fruits.size();
        vector<vector<int>> dp1(n, vector<int>(n, -1));
        vector<vector<int>> dp2(n, vector<int>(n, -1));
        int ans = 0;
        for(int i=0; i<n; i++) ans += fruits[i][i];
        ans += f1(fruits, n-1, 0, n, dp1);
        ans += f2(fruits, 0, n-1, n, dp2);
        return ans;
    }
};