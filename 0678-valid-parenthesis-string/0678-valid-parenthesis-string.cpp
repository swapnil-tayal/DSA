class Solution {
public:
    
    int f(int i, string &s, int cnt, vector<vector<int>> &dp){
        
        if(i == s.size()){
            if(cnt == 0) return 1;
            else return 0;
        }
        if(dp[i][cnt+100] != -1) return dp[i][cnt+100];
        
        int ans = 0;
        
        if(s[i] == '(') ans = ans | f(i+1, s, cnt+1, dp);
        else if(s[i] == ')'){
            if(cnt >= 1){
                ans = ans | f(i+1, s, cnt-1, dp);
            }
        }
        else{
            ans = ans | f(i+1, s, cnt+1, dp);
            if(cnt >= 1) ans = ans | f(i+1, s, cnt-1, dp);
            ans = ans | f(i+1, s, cnt, dp);
        }
        return dp[i][cnt+100] = ans;
    }
    
    bool checkValidString(string s) {
        
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(202, -1));
        return f(0, s, 0, dp);
    }
};