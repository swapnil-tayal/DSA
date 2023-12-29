class Solution {
    int mod;
    bool isValid(string s, int prev, int i, char ch1 = '.', char ch2 = '.'){
        
        if(ch1 != '.') s[prev] = ch1;
        if(ch2 != '.') s[i] = ch2;
        
        int n = s.size();
        if(s[prev] == '0') return false;
        
        int val = 0;
        for(int k=prev; k<=i; k++){
            val = val*10 + (s[k]-'0');
        }
        if(val >= 1 && val <= 26) return true;
        else return false;
    }
public:
    
    long long f(int i, string &s, vector<int> &dp){
        
        if(i == s.size()) return 1;
        if(dp[i] != -1) return dp[i];
        
        long long ans = 0;
        if(i+1 < s.size()){
            if(s[i] != '*' and s[i+1] != '*'){
                if(isValid(s, i, i+1)) ans = (ans + f(i+2, s, dp)) % mod;
                if(s[i] != '0') ans = (ans + f(i+1, s, dp)) % mod;
                
            }else if(s[i] == '*' and s[i+1] == '*'){
                ans = (ans + (15 * f(i+2, s, dp))) % mod;
                ans = (ans + (9 * f(i+1, s, dp))) % mod;
                        
            }else if(s[i] == '*' and s[i+1] != '*'){
                int x = 2;
                if(s[i+1] == '7' || s[i+1] == '8' || s[i+1] == '9') x = 1; 
                ans = (ans + (x * f(i+2, s, dp))) % mod;
                ans = (ans + (9 * f(i+1, s, dp))) % mod; 
                    
            }else if(s[i] != '*' and s[i+1] == '*'){
                int x = 0;
                if(s[i] == '1') x = 9;
                else if(s[i] == '2') x = 6;
                ans = (ans + (x * f(i+2, s, dp))) % mod;
                if(s[i] != '0') ans = (ans + f(i+1, s, dp)) % mod;
            }
        
        }else{
            if(s[i] == '*'){
                ans = (ans + (9 * f(i+1, s, dp))) % mod;
            }else if(s[i] != '0'){
                ans = (ans + f(i+1, s, dp)) % mod;
            }
        }
        return dp[i] = ans;
    }
     
    int numDecodings(string s) {
        
        this->mod = 1000000007;
        vector<int> dp(s.size(), -1);
        return f(0, s, dp);
    }
};