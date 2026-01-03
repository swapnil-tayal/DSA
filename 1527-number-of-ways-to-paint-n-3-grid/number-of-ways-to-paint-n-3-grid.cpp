class Solution { 
    vector<string> a = {
        "ryr", "yry", "gry", "ryg", "yrg", "grg", "rgr", "ygr", "gyr", "rgy", "ygy", "gyg"
    };
    int mod = int(1e9+7);
public:

    int isValid(string s1, string s2){
        for(int i=0; i<3; i++){
            if(s1[i] == s2[i]) return 0;
        }
        return 1;
    }

    int f(int i, int n, int prev, vector<vector<int>> &dp){

        if(i == n) return 1;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int ans = 0;
        if(prev == -1){
            for(int k=0; k<a.size(); k++) ans = (ans + f(i+1, n, k, dp)) % mod;
        }else{
            for(int k=0; k<a.size(); k++){
                if(isValid(a[k], a[prev])) ans = (ans + f(i+1, n, k, dp)) % mod;
            }
        }
        return dp[i][prev+1] = ans;
    }

    int numOfWays(int n) {

        vector<vector<int>> dp(n, vector<int>(13, -1));
        return f(0, n, -1, dp);   
    }
};