class Solution {
    vector<vector<vector<int>>> dp;
public:

    int f(int i, int j, int skip, vector<vector<int>> &coins){

        if(i == coins.size() || j == coins[0].size()) return -1e9;
        if(i == coins.size()-1 and j == coins[0].size()-1){
            if(skip) return max(coins[i][j], 0);
            else return coins[i][j];
        }
        if(dp[i][j][skip] != -1) return dp[i][j][skip];

        int right = coins[i][j] + f(i+1, j, skip, coins);
        if(skip > 0) right = max(right, f(i+1, j, skip-1, coins));
        int down = coins[i][j] + f(i, j+1, skip, coins);
        if(skip > 0) down = max(down, f(i, j+1, skip-1, coins));

        return dp[i][j][skip] = max(down, right);

    }

    int maximumAmount(vector<vector<int>>& coins) {
        
        dp.resize(coins.size()+1, vector<vector<int>>(coins[0].size()+1, vector<int>(3, -1e9)));
    
        int n = coins.size();
        int m = coins[0].size();

        for(int k=0;k<=2;k++){
            if(k > 0) dp[n-1][m-1][k] = max(coins[n-1][m-1], 0);
            else dp[n-1][m-1][k] = coins[n-1][m-1];
        }

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                
                if(i==n-1 && j==m-1) continue;

                for(int skip=0; skip<=2; skip++){

                    int right = -1e9, down = -1e9;
                    right = coins[i][j] + dp[i+1][j][skip];
                    if(skip > 0) right = max(right, dp[i+1][j][skip-1]);
                    down = coins[i][j] + dp[i][j+1][skip];
                    if(skip > 0) down = max(down, dp[i][j+1][skip-1]);
                    dp[i][j][skip] = max(right, down);
                }
            }
        }
        return dp[0][0][2];
    }
};