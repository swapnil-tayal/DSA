class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        int n = nums.size();
        int i = 0;
        int j = 0;
        
        map<int,int> mp;
        int ans = 0;
        
        while(j < n){
            
            mp[nums[j]]++;
            
            if(mp[nums[j]] <= k){
                ans = max(ans, j-i+1);
                j++;
            
            }else{
                
                while(mp[nums[j]] > k){
                    mp[nums[i]]--;
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};