class Solution {
    vector<vector<int>> dp;
public:

    bool f(int i, string s, int sum){

        if(sum < 0) return 0;
        if(i == s.size()) return sum == 0;

        if(dp[i][sum] != -1) return dp[i][sum];
        bool ans = false;
        if(s[i] == '(') ans = ans || f(i+1, s, sum+1);
        else if(s[i] == ')') ans = ans || f(i+1, s, sum-1);
        else{
            ans = ans || f(i+1, s, sum+1);
            ans = ans || f(i+1, s, sum-1);
            ans = ans || f(i+1, s, sum);
        }
        return dp[i][sum] = ans;
    }

    bool checkValidString(string s) {
        
        int n = s.size();
        dp.resize(n, vector<int>(n+1, -1));
        return f(0, s, 0);
    }
};