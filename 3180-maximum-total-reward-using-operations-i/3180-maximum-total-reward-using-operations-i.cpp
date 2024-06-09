class Solution {
    int ans = 0;
public:
    
    void f(int i, vector<int> &arr, int sum, vector<vector<int>> &dp){
        
        if(i == arr.size()){
            ans = max(ans, sum);
            return;
        }
        
        if(dp[i][sum]) return;
        
        if(sum < arr[i]) f(i+1, arr, sum+arr[i], dp);
        f(i+1, arr, sum, dp);
        
        dp[i][sum] = 1;
        return;
    }
    
    int maxTotalReward(vector<int>& arr) {
        
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> dp(n, vector<int>(4001, 0));
        int sum = 0;
        f(0, arr, sum, dp);
        return ans;
    }
};