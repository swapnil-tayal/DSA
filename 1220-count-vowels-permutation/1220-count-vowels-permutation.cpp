#define mod 1000000007;

class Solution{
    
public:
    
    long long f(int i, int prev, vector<vector<long long>> &dp){
        
        if(i == 0) return 1;
        if(dp[i][prev] != -1) return dp[i][prev];
        
        long long ans = 0;
        if(prev == 0){
            ans += f(i-1, 1, dp) % mod
            ans += f(i-1, 2, dp) % mod
            ans += f(i-1, 3, dp) % mod
            ans += f(i-1, 4, dp) % mod
            ans += f(i-1, 5, dp) % mod;
        
        }else if(prev == 1) {
            ans = f(i-1, 2, dp) % mod;
 
        }else if(prev == 2){
            ans += f(i-1, 1, dp) % mod
            ans += f(i-1, 3, dp) % mod; 
        
        }else if(prev == 3){
            ans += f(i-1, 1, dp) % mod; 
            ans += f(i-1, 2, dp) % mod; 
            ans += f(i-1, 4, dp) % mod; 
            ans += f(i-1, 5, dp) % mod;

        }else if(prev == 4){
            ans += f(i-1, 3, dp) % mod
            ans += f(i-1, 5, dp) % mod;

        }else ans = f(i-1, 1, dp) % mod;
        
        return dp[i][prev] = ans % mod;
    }
    
    int countVowelPermutation(int n) {
        
        vector<char> a = {'a', 'e', 'i', 'o', 'u'}; 
        
        vector<vector<long long>> dp(n+1, vector<long long>(6, -1));
        return f(n, 0, dp);
    }
};