class Solution {
    vector<vector<vector<int>>> dp;
    int mod = (1e9+7);
public:

    int f(int i, int g1, int g2, vector<int> &nums){

        if(i == nums.size()) return (g1 != 0 && g1 == g2);
        if(dp[i][g1][g2] != -1) return dp[i][g1][g2];
        int witha = f(i+1, __gcd(g1, nums[i]), g2, nums);
        int withb = f(i+1, g1, __gcd(g2, nums[i]), nums);
        int skip = f(i+1, g1, g2, nums);
        return dp[i][g1][g2] = ((witha + withb) % mod + skip) % mod;
    }

    int subsequencePairCount(vector<int>& nums) {
        
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        dp.assign(n, vector<vector<int>>(maxi+1, vector<int>(maxi+1, -1)));
        return f(0, 0, 0, nums);
    }
};