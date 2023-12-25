class Solution {
public:
    
    bool f(string &s, int prev, int i){
        
        int n = s.size();
        if(s[prev] == '0') return false;
        
        int val = 0;
        for(int k=prev; k<=i; k++){
            val = val*10 + (s[k]-'0');
        }
        if(val >= 1 && val <= 26) return true;
        else return false;
    }
    
    int f(int i, int prev, string &s, vector<vector<int>> &dp){
        
        if(i-prev+1 > 2) return 0;
        
        if(i == s.size()){
            if(prev == s.size()) return 1;
            else return 0;
        }
        if(dp[i][prev] != -1) return dp[i][prev];
        
        int npick = f(i+1, prev, s, dp);
        int pick = 0;
        if(f(s, prev, i)) pick = f(i+1, i+1, s, dp);
        
        return dp[i][prev] = pick + npick;
    }
    
    int numDecodings(string s) {
        
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, 0, s, dp);
    }
};