class Solution {
public:
    
    int f(int i, int d, int maxi, vector<int> &arr, vector<vector<vector<int>>> &dp){
        
        if(i == arr.size()){
            if(d == 1) return maxi;
            else return 1e9;
        }
        if(dp[i][d][maxi] != -1) return dp[i][d][maxi];
        
        int notBreak = f(i+1, d, max(maxi, arr[i]), arr, dp);
        int breakPoint = 1e9; 
        if(d >= 2 and i != 0){
            breakPoint = maxi + f(i+1, d-1, arr[i], arr, dp);
        }
        return dp[i][d][maxi] = min(notBreak, breakPoint);
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        int n = jobDifficulty.size();
        if(n < d) return -1;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(d+1, vector<int>(1001, -1)));
        return f(0, d, 0, jobDifficulty, dp);
    }
};