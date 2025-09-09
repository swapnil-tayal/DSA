class Solution {
    char ch = 'A';
public:

    int f(int day, int n, int delay, int forget, vector<int> &dp){
        
        if(day > n) return 0;
        if(dp[day] != -1) return dp[day];
        int ans = 0;
        if(day + forget > n) ans = 1; // only for person who can not share with anyone, as for other recursion will handle
        for(int i=day+delay; i<day+forget; i++){
            ans = (ans + f(i, n, delay, forget, dp)) % (1000000007);
        }
        return dp[day] = ans;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        
        vector<int> dp(n+1, -1);
        return f(1, n, delay, forget, dp);
    }
};