class Solution {
public:
    
    int f(int i, int ch1, int ch2, vector<string> &words, vector<vector<vector<int>>> &dp){
        
        if(i == words.size()-1){
            if(words[i][0] == ch2 || words[i].back() == ch1) return words[i].size()-1;
            else return words[i].size();
        }
        if(dp[i][ch1][ch2] != -1) return dp[i][ch1][ch2];
        
        int ch3 = words[i+1][0] - 'a';
        int ch4 = words[i+1].back() - 'a';
        
        int ans= 1e9;
        if(ch2 == ch3){
            ans = words[i].size()-1 + f(i+1, ch1, ch4, words, dp);
        }else{
            ans = min(ans, (int)words[i].size() + f(i+1, ch1, ch4, words, dp));
        }
        if(ch4 == ch1){
            ans = min(ans, (int)words[i].size()-1 + f(i+1, ch3, ch2, words, dp));
        }else{
            ans = min(ans, (int)words[i].size() + f(i+1, ch3, ch2, words, dp));
        }
        return dp[i][ch1][ch2] = ans;
    }
    
    int minimizeConcatenatedLength(vector<string>& words) {
        
        int n = words.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(27, vector<int>(27, -1)));
        return f(0, words[0][0]-'a', words[0].back()-'a', words, dp);
    }
};