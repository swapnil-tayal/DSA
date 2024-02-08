class Solution {
    
    vector<int> arr;
public:
    
    int f(int i, int tar, vector<vector<int>> &dp){
        
        if(i == arr.size()){
            if(tar == 0) return 0;
            else return 1e9;
        }
        if(dp[i][tar] != -1) return dp[i][tar];
        int npick = f(i+1, tar, dp);
        int pick = 1e9;
        if(tar - arr[i] >= 0) pick = 1 + f(i, tar- arr[i], dp);
        return dp[i][tar] = min(npick, pick);
    }
    
    int numSquares(int n) {
        
        int i = 1;
        while(i*i <= n){
            arr.push_back(i*i);
            i++;
        }
        vector<vector<int>> dp(arr.size(), vector<int>(n+1, -1));
        return f(0, n, dp);
    }
};