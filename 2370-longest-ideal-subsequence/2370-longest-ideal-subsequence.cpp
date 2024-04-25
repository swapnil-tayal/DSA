class Solution {
    int k;
public:
    
    int f2(char ch1, char ch2){
        return abs(ch1-ch2) <= k;
    }
    int f(int i, string &s, char ch, vector<vector<int>> &dp){
        
        if(i == s.size()) return 0;
        if(dp[i][ch-'a'] != -1) return dp[i][ch-'a'];
        
        int npick = f(i+1, s, ch, dp);
        int pick = 0;
        
        if(ch == '{' || f2(ch, s[i])){
            pick = 1 + f(i+1, s, s[i], dp);
        }
        return dp[i][ch-'a'] = max(pick, npick);
    }
    
    int longestIdealString(string s, int k) {
        this->k = k;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(27, -1));
        return f(0, s, '{', dp);
    }
};