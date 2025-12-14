class Solution {
    int mod = int(1e9+7);
public:

    int f(int i, string &str, int seats, vector<vector<int>> &dp){

        if(i == str.size()){
            if(seats == 2) return 1;
            else return 0;
        }
        if(dp[i][seats] != -1) return dp[i][seats];
        int ans = 0;
        if(str[i] == 'S'){
            if(seats < 2) ans = (ans + f(i+1, str, seats+1, dp)) % mod;
            else ans = (ans + f(i+1, str, 1, dp)) % mod;
        }else{
            if(seats < 2) ans = (ans + f(i+1, str, seats, dp)) % mod;
            else{
                ans = (ans + f(i+1, str, seats, dp)) % mod;
                ans = (ans + f(i+1, str, 0, dp)) % mod;
            }
        }
        return dp[i][seats] = ans;
    }

    int numberOfWays(string corridor) {
        vector<vector<int>> dp(corridor.size(), vector<int>(3, -1));
        return f(0, corridor, 0, dp);
    }
};