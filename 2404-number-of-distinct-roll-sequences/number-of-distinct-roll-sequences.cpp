class Solution {
public:

    int f(int i, int n, int prev, int prev2, vector<vector<vector<int>>> &dp){

        if(i == n){
            return 1;
        }
        if(dp[i][prev][prev2] != -1) return dp[i][prev][prev2];
        long long ans = 0;
        for(int k=1; k<=6; k++){
            if((prev == 0 || __gcd(prev, k) == 1) and k != prev and k != prev2){
                ans = (ans + f(i+1, n, k, prev, dp)) % (int)(1e9+7);
            }
        }
        return dp[i][prev][prev2] = ans;
    }

    int distinctSequences(int n) {
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(7, vector<int>(7, -1)));
        return f(0, n, 0, 0, dp);        
    }
};