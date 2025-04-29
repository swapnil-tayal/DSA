class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        int cnt = 0;

        long long ans = 0;
        int i = 0;
        int j = 0;
        while(j < n){

            cnt += (nums[j] == maxi);
            if(cnt < k) j++;
            else{

                while(i<n and cnt >= k){
                    ans += (n-j);
                    cnt -= (nums[i] == maxi);
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};