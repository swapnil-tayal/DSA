class Solution {
public:
    
    int check(int i, int prev, string &str, vector<string> &a){
        
        string s;
        for(int k=prev; k<=i; k++){
            s += str[k];
        }
        // if(prev == 0 and i == 3){
        //     cout<<i<<' '<<prev<<'-';
        //     cout<<s<<' '; 
        //     // cout<<s.size()<<' ';
        // }
        for(auto &t: a){
            // if(prev == 0 and i == 3) cout<<i<<' ';
            if(t == s){
                // cout<<t<<' ';
                return 1;
            }
        }
        return 0;
    }
    
    int f(int i, int prev, string &s, vector<string> &a, vector<vector<int>> &dp){
        
        if(i == s.size()){

            if(prev == s.size()) return 0;
            if(check(i-1, prev, s, a)) return 0;
            else return i - prev;

        }
        if(dp[i][prev] != -1) return dp[i][prev];
        
        int extend = f(i+1, prev, s, a, dp);
        
        int npick = (i-prev+1) + f(i+1, i+1, s, a, dp);
        int pick = 1e9;
        if(check(i, prev, s, a)) pick = f(i+1, i+1, s, a, dp);
        
        return dp[i][prev] = min({extend, npick, pick});
        
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(0, 0, s, dictionary, dp);
    }
};