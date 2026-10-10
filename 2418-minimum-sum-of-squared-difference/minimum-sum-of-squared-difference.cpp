class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {

        int n = nums1.size();
        vector<long long> a(100001, 0);

        for(int i=0; i<n; i++){
            a[abs(nums1[i] - nums2[i])]++;
        }

        long long total = k1 + k2;
        for (int i=100000; i>0; i--) {
            long long take = min(total, a[i]);
            a[i] -= take;
            a[i - 1] += take;
            total -= take;
        }

        long long ans = 0;
        for (int i=0; i<=100000; i++) {
            ans += 1LL * i * i * a[i];
        }
        return ans;
    }
};