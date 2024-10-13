class Solution {
public:
    
    int f(int i, string &s, int prev, int sum, vector<vector<vector<int>>> &dp){
        
        if(i == s.size()) return sum > 0;
        
        if(dp[i][prev][sum+1000] != -1) return dp[i][prev][sum+1000];
        int ways = 0;
        if(s[i] == 'F'){
            
            if(prev != 1) ways = (ways + f(i+1, s, 1, sum, dp)) % int(1e9+7);
            if(prev != 2) ways = (ways + f(i+1, s, 2, sum + 1, dp)) % int(1e9+7);
            if(prev != 3) ways = (ways + f(i+1, s, 3, sum - 1, dp)) % int(1e9+7);
            
        }else if(s[i] == 'E'){
            
            if(prev != 1) ways = (ways + f(i+1, s, 1, sum + 1, dp)) % int(1e9+7);
            if(prev != 2) ways = (ways + f(i+1, s, 2, sum - 1, dp)) % int(1e9+7);
            if(prev != 3) ways = (ways + f(i+1, s, 3, sum, dp)) % int(1e9+7);
            
        }else{
            
            if(prev != 1) ways = (ways + f(i+1, s, 1, sum - 1, dp)) % int(1e9+7);
            if(prev != 2) ways = (ways + f(i+1, s, 2, sum, dp)) % int(1e9+7);
            if(prev != 3) ways = (ways + f(i+1, s, 3, sum + 1, dp)) % int(1e9+7);
            
        }
        return dp[i][prev][sum+1000] = ways % int(1e9+7);
    }
    
    int countWinningSequences(string s) {
        
        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(4, vector<int>(2001, -1)));
        return f(0, s, 0, 0, dp);
    }
};