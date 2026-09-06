class Solution {
    vector<vector<int>> dp;
public:

    int f(int i, int j, string &s, string &t){

        if(j == t.size()) return 1;
        if(i == s.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(s[i] == t[j]){
            ans = f(i+1, j+1, s, t);
        }   
        ans += f(i+1, j, s, t);
        return dp[i][j] = ans;
    }

    int numDistinct(string s, string t) {
        
        dp.assign(s.size(), vector<int>(t.size(), -1));
        return f(0, 0, s, t);
    }
};