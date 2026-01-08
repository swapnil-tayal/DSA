class Solution {
public:

    int f(int i, int j, vector<int> &nums1, vector<int> &nums2, int picked, vector<vector<vector<int>>> &dp){

        if(i == nums1.size() || j == nums2.size()) return picked ? 0 : -1e9;
        if(dp[i][j][picked] != -1) return dp[i][j][picked];
        int ans = -1e9;
        ans = max(ans, f(i+1, j, nums1, nums2, picked, dp));
        ans = max(ans, f(i, j+1, nums1, nums2, picked, dp));
        ans = max(ans, (nums1[i] * nums2[j]) + f(i+1, j+1, nums1, nums2, 1, dp));
        return dp[i][j][picked] = ans;
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<vector<int>>> dp(nums1.size(), vector<vector<int>>(nums2.size(), vector<int>(2, -1)));
        return f(0, 0, nums1, nums2, 0, dp);
    }
};