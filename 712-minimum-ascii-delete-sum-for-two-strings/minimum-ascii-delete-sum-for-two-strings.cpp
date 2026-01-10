class Solution {
public:

    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){

        if(i == s1.size()){
            int sum = 0;
            for(int k=j; k<s2.size(); k++) sum += s2[k];
            return sum;
        }
        if(j == s2.size()){
            int sum = 0;
            for(int k=i; k<s1.size(); k++) sum += s1[k];
            return sum;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 1e9;
        ans = min(ans, int(s1[i]) + f(i+1, j, s1, s2, dp));
        ans = min(ans, int(s2[j]) + f(i, j+1, s1, s2, dp));
        ans = min(ans, int(s2[j]) + int(s1[i]) + f(i+1, j+1, s1, s2, dp));
        if(s1[i] == s2[j]){
            ans = min(ans, f(i+1, j+1, s1, s2, dp));
        }
        return dp[i][j] = ans;
    }

    int minimumDeleteSum(string s1, string s2) {
        
        vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), -1));
        return f(0, 0, s1, s2, dp);
    }
};