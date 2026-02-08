class Solution {
public:

    // long long f(int i, int j, vector<int> &nums1, vector<int> &nums2, int k){
    //     if(i == nums1.size() || j == nums2.size() || k == 0){
    //         return k == 0 ? 0 : -1e15;
    //     }
    //     if(dp[i][j][k] != -1) return dp[i][j][k];
    //     long long pick = (1ll * nums1[i] * nums2[j]) + f(i+1, j+1, nums1, nums2, k-1);
    //     long long npick = max(f(i+1, j, nums1, nums2, k), f(i, j+1, nums1, nums2, k));
    //     return dp[i][j][k] = max(pick, npick);
    // }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        
        vector<vector<vector<long long>>> dp(n+1, vector<vector<long long>>(m+1, vector<long long>(k+1, -1e15)));

        for (int i=0; i<=n; i++) {
            for (int j=0; j<=m; j++) {
                dp[i][j][0] = 0;
            }
        }

        for (int i=n-1; i>=0; i--) {
            for (int j=m-1; j>=0; j--) {
                for (int rem=1; rem<=k; rem++) {
                    long long pick = (1LL * nums1[i] * nums2[j]) + dp[i+1][j+1][rem-1];
                    long long npick = max(dp[i+1][j][rem], dp[i][j+1][rem]);
                    dp[i][j][rem] = max(pick, npick);
                }
            }
        }
        return dp[0][0][k];
    }
};