class Solution {
    int mod = int(1e9)+7;
public:

    long long f(char ch, int t, vector<vector<long long>> &dp){

        if(t == 0) return 0;
        long long ans = 0;
        if(dp[ch-'a'][t] != -1) return dp[ch-'a'][t];

        if(ch != 'z'){
            ans = f(ch+1, t-1, dp) % mod;
        }else{
            ans = f('a', t-1, dp) % mod;
            ans = (ans + f('b', t-1, dp)) % mod;
            ans = (ans + 1) % mod;
        }
        return dp[ch-'a'][t] = ans;
    }

    int lengthAfterTransformations(string s, int t) {
        
        vector<vector<long long>> dp(26, vector<long long>(t+1, -1));
        map<char,long long> mp;
        for(auto &i: s) mp[i]++;
        long long ans = 0;
        for(auto &i: mp){
            ans = (ans + (i.second * (long long)(1 + f(i.first, t, dp)))) % mod;
        }
        return ans;
    }
};