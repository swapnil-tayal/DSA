class Solution {
public:
    
    int f(int i, int j, int ch, vector<int> &nums1, vector<int> &nums2, vector<vector<vector<int>>> &dp){
        
        if(i == nums1.size() || j == nums2.size()){
            if(ch) return 0;
            else return -1e9;
        }
        if(dp[i][j][ch] != -1) return dp[i][j][ch];
        
        int pick = (nums1[i] * nums2[j]) + f(i+1, j+1, 1, nums1, nums2, dp);
        int npick1 = f(i+1, j, ch, nums1, nums2, dp);
        int npick2 = f(i, j+1, ch, nums1, nums2, dp);
        
        return dp[i][j][ch] = max({ pick, npick1, npick2 });
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2, -1)));
        return f(0, 0, 0, nums1, nums2, dp);
    }
};