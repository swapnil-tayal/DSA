class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int maxi = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        int j = 0;
        long long cnt = 0;
        long long ans = 0;
        while(j < n){
            
            cnt += (nums[j] == maxi);
            if(cnt < k) j++;
            else{
                
                while(cnt >= k){
                    ans += n-j;
                    cnt -= (nums[i] == maxi);
                    i++;
                }j++;
            }
        }
        return ans;
    }
};