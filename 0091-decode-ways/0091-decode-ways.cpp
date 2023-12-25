class Solution {
public:
    
    bool isValid(string &s, int prev, int i){
        
        int n = s.size();
        if(s[prev] == '0') return false;
        
        int val = 0;
        for(int k=prev; k<=i; k++){
            val = val*10 + (s[k]-'0');
        }
        if(val >= 1 && val <= 26) return true;
        else return false;
    }
    
    int f(int i, string &s, vector<int> &dp){
        
        if(i == s.size()) return 1;
        if(dp[i] != -1) return dp[i];
        
        int ans = 0;
        if(i+1 < s.size() && isValid(s, i, i+1)){
            ans += f(i+2, s, dp);
        }
        if(isValid(s, i, i)) ans += f(i+1, s, dp);
        return dp[i] = ans;
    }
    
    int numDecodings(string s) {
        
        int n = s.size();
        vector<int> dp(n, -1);
        return f(0, s, dp);
    }
};