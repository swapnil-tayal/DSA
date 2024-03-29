class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int maxi = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        
        int j = 0;
        int i = 0;
        int cntMaxi = 0;
        
        long long ans = 0;
        while(j < n){
            
            cntMaxi += (nums[j] == maxi);
            if(cntMaxi < k){
                j++;
            }else{
                
                while(i<n and cntMaxi >= k){
                    ans += n-j;
                    cntMaxi -= (nums[i] == maxi);
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};