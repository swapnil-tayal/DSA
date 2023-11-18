class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int i = 0;
        int j = 0;
        long long ans = 0;
        long long sum = 0;
        
        while(j < n){
            
            sum += nums[j];
            long long req = (long long)nums[j] * (long long)(j-i+1);
            
            if(sum + k >= req){
                ans = max(ans, (long long)j-i+1);
                j++;
            }
            else{
                while(i<n and sum+k < req){
                    sum -= nums[i];
                    req -= nums[j];
                    i++;
                }
                j++;
                // if(sum+k >= req){
                    // ans = max(ans, (long long)j-i+1);
                // }
            }
        }
        return ans;
    }
};