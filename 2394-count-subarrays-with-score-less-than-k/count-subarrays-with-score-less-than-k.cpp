class Solution {
public:

    int f(int i, vector<int> &nums, vector<long long> &pre, long long k){

        int n = nums.size();
        long long s = i;
        long long e = n-1;
        long long ans = 0;
        while(s <= e){
            long long mid = (s+e)/2;
            long long sum = pre[mid] - ((i-1>=0) ? pre[i-1] : 0);
            if(sum * (mid-i+1) < k){
                ans = mid-i+1;
                s = mid+1;
            }else e = mid-1;
        }
        return ans;
    }

    long long countSubarrays(vector<int>& nums, long long k) {
        
        int n = nums.size();
        vector<long long> pre(n, 0);
        pre[0] = nums[0];
        for(int i=1; i<n; i++){
            pre[i] = pre[i-1] + nums[i];
        }
        long long ans = 0;
        for(int i=0; i<n; i++){
            int res = f(i, nums, pre, k);
            ans += f(i, nums, pre, k);
        }
        return ans;
    }
};