class Solution {
public:
    
    int f(int i, int d, vector<int> &arr, vector<vector<int>> &dp){
        
        if(i == arr.size()){
            if(d == 0) return 0;
            else return 1e9;
        }
        if(dp[i][d] != -1) return dp[i][d];
        if(d == 0) return 1e9;
        int ans = 1e9;
        int maxi = 0;
        for(int k=i; k<arr.size(); k++){
            maxi = max(maxi, arr[k]);
            int cut = maxi + f(k+1, d-1, arr, dp);
            ans = min(ans, cut);
        }
        return dp[i][d] = ans;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        int n = jobDifficulty.size();
        vector<vector<int>> dp(n, vector<int>(d+1, -1));
        int ans = f(0, d, jobDifficulty, dp); 
        return ans == 1e9 ? -1 : ans;
    }
};