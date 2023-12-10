class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int maxi = *max_element(nums.begin(), nums.end());
        int i = 0;
        int j = 0;
        int cnt = 0;
        long long sum = 0;
        long long n = nums.size();
        
        while(j < n){
            
            if(nums[j] == maxi) cnt++;
            if(cnt < k){
                sum += j-i+1;
                j++;
            
            }else{
                while(i<=j and cnt >= k){
                    cnt -= (nums[i]==maxi);
                    i++;
                }
                sum += j-i+1;
                j++;
            }
        }
        return n*(n+1)/2 - sum;
    }
};