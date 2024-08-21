class Solution {
public:
    
    int f(int i, int j, string &s, vector<vector<int>> &dp){
        
        if(i == j) return 1;
        if(j-i+1 == 2){
            if(s[i] == s[j]) return 1;
            return 2;
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        int cnt = 1e9;
        for(int k=i; k<j; k++){
            
            int x = f(i, k, s, dp) + f(k+1, j, s, dp);
            cnt = min(cnt, x);
        }
        if(s[i] == s[j]) --cnt;
        return dp[i][j] = cnt;
    }
    
    int strangePrinter(string s) {
        
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, n-1, s, dp);
    }
};