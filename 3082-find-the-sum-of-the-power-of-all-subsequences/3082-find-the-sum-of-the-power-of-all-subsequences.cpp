class Solution {
    int mod = int(1e9 + 7);
    vector<int> pre;
public:
    
    int f(int i, int sum, int cnt, vector<int> &nums, vector<vector<vector<int>>> &dp){
        
        if(sum < 0) return 0;
        if(i == nums.size()){
            if(sum == 0) return pre[cnt];
            else return 0;
        }
        if(dp[i][sum][cnt] != -1) return dp[i][sum][cnt];
        
        int pick = f(i+1, sum-nums[i], cnt+1, nums, dp);
        int npick = f(i+1, sum, cnt, nums, dp);
        return dp[i][sum][cnt] = (pick + npick) % mod;
    }
    
    int sumOfPower(vector<int>& nums, int k) {
        
        int n = nums.size();
        pre.resize(n+1, 0);
        
        int num = 1;
        for(int i=n; i>=0; i--){
            pre[i] = num;
            num = (num*2)%mod;
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(n+1, -1)));
        return f(0, k, 0, nums, dp);
    }
};