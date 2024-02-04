class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        long long ans = -1e15;
        
        map<long long, long long> mp;
        long long sum = 0;
        
        for(int i=0; i<n; i++){
            
            if(mp.find(nums[i]-k) != mp.end()){
                // cout<<nums[i]<<' '<<mp[nums[i]-k]<<'\n';
                ans = max(ans, sum+nums[i] - mp[nums[i]-k]);
            }
            if(mp.find(nums[i]+k) != mp.end()){
                // cout<<nums[i]<<' '<<mp[nums[i]+k]<<'\n';
                ans = max(ans, sum+nums[i] - mp[nums[i]+k]);
            }
            
            if(mp.find(nums[i]) != mp.end()) mp[nums[i]] = min(mp[nums[i]], sum);
            else mp[nums[i]] = sum;
            sum += nums[i];
        }
        return ans == -1e15 ? 0 : ans;
    }
};