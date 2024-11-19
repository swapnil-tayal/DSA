class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        int i = 0;
        int j = 0;
        map<int,int> mp;
        long long sum = 0;
        long long ans = 0;
        
        while(j < n){
            
            mp[nums[j]]++;
            sum += nums[j];
            if(j-i+1 < k) j++;
            else{
                
                if(mp.size() == k) ans = max(ans, sum);
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                sum -= nums[i];
                i++;
                j++;
            }
        }
        return ans;
    }
};