class Solution {
    const int mod = 1e9+7;
public:
    
    int f(int i, int seat, string &str, vector<vector<int>> &dp){
        
        if(str[i] == 'S') seat++;
        if(seat > 2) return 0;
        
        if(i == str.size()-1){
            return seat == 2;
        }
        
        if(dp[i][seat] != -1) return dp[i][seat];
        
        if(seat <= 1){
            int ncut = f(i+1, seat, str, dp);
            return dp[i][seat] = ncut;
            
        }else{
            int cut = f(i+1, 0, str, dp);
            int ncut = f(i+1, seat, str, dp);
            return dp[i][seat] = (cut + ncut) % mod;
        }
    }
    
    int numberOfWays(string str) {
        
        int n = str.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return f(0, 0, str, dp);
    }
};