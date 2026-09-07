class Solution {
public:
    int distinctSubseqII(string s) {
        
        int mod = (1e9+7);
        int total = 0;
        vector<int> dp(26, 0);
        for(auto &ch: s){

            int ind = ch - 'a';
            int add = (total - dp[ind] + mod) % mod;
            dp[ind] = 1 + total;
            total = (dp[ind] + add) % mod;
        }
        return total;
    }
};