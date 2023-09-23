class Solution {
public:
    
    int f(int i, int k, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp){
        
        if(i == nums1.size()) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        
        int a = 0;
        int b = 0;
        if(k == 0){
            a = nums1[i] + f(i+1, 0, nums1, nums2, dp);
            b = nums2[i] + f(i+1, 1, nums1, nums2, dp);
        
        }else if(k == 1){
            b = nums2[i] + f(i+1, 1, nums1, nums2, dp);
            a = nums1[i] + f(i+1, 2, nums1, nums2, dp);
            
        }else{
            a = nums1[i] + f(i+1, 2, nums1, nums2, dp);
        }
        return dp[i][k] = max(a, b);
    }
    
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>> dp1(nums1.size(), vector<int>(3, -1));
        int a = f(0, 0, nums1, nums2, dp1);
        
        vector<vector<int>> dp2(nums1.size(), vector<int>(3, -1));
        int b = f(0, 0, nums2, nums1, dp2);
        
        return max(a, b);
    }
};