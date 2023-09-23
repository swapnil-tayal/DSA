bool cmp(string &s1, string &s2){
    return s1.size() < s2.size();
}
class Solution {
public:
    
    int check(string &s1, string &s2){
        
        if(s1.size()+1 != s2.size()) return 0;
        int j = 0;
        for(int i=0; i<s2.size(); i++){
            if(s2[i] == s1[j]) j++;
            if(j == s1.size()) return 1;
        }
        return j == s1.size();
    }
    
    int f(int i, int prev, vector<string> &words, vector<vector<int>> &dp){
        
        if(i == words.size()) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        
        int pick = 0;
        int npick = 0;
        
        if(prev == -1){
            pick = 1 + f(i+1, i, words, dp);
            npick = f(i+1, prev, words, dp);
        
        }else{
            if(check(words[prev], words[i])){
                pick = 1 + f(i+1, i, words, dp);
            }
            npick = f(i+1, prev, words, dp);
        }
        return dp[i][prev+1] = max(pick, npick);
    }
    
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(), words.end(), cmp);
        
        // for(auto i: words) cout<<i<<' ';
        // return -1;
        int n = words.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(0, -1, words, dp);
    }
};