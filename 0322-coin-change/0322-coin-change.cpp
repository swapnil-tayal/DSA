class Solution {
public:
    
    int f(int i, vector<int> &coins, int amt, vector<vector<int>> &dp){
        
        if(amt < 0) return 1e9;
        if(i == coins.size()){
            
            if(amt == 0) return 0;
            else return 1e9;
        }
        
        if(dp[i][amt] != -1) return dp[i][amt];
        
        int npick = f(i+1, coins, amt, dp);
        int pick = 1 + f(i, coins, amt - coins[i], dp);
        return dp[i][amt] = min(npick, pick);
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int k= f(0, coins, amount, dp);
        return k == 1e9 ? -1 : k;
    }
};