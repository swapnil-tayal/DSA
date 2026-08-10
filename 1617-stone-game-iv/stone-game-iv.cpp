class Solution {
    vector<vector<int>> dp;
public:

    bool f(int n, int alice){

        if(n == 0){
            if(alice) return 0;
            else return 1;
        }
        if(dp[n][alice] != -1) return dp[n][alice];
        int ind = 1;
        bool ans = alice ? false : true;
        while((ind * ind) <= n){
            int val = ind * ind;
            if(alice) ans = ans || f(n-val, 1-alice);
            else ans = ans && f(n-val, 1-alice);
            ind++;
        }
        return dp[n][alice] = ans;
    }

    bool winnerSquareGame(int n) {
        
        dp.assign(n+1, vector<int>(2, -1));
        return f(n, 1);
    }
};