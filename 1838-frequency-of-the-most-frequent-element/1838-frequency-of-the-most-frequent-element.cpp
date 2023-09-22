class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int i = 0;
        int j = 0;
        int ans = 0;
        long long sm = 0;
        
        while(j < n){
            
            sm += nums[j];
            long long req = (long long)(j-i+1)*(long long)nums[j];
            
            if(req-sm <= k){
                
                ans = max(ans, j-i+1);
                j++;
            
            }else{
                
                while(req - sm > k){
                    sm -= nums[i];
                    req -= nums[j];
                    i++;
                }
                ans = max(ans, j-i+1);
                j++;
            }
        }
        return ans;
    }
};