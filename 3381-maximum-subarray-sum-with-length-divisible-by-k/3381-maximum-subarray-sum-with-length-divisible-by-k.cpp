class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        long long sum = 0;
        map<int,long long> mp;
        long long ans = -1e18;
        
        for(int i=0; i<n; i++){
            
            sum += nums[i];
            int currInd = i+1;
            
            if(currInd % k == 0) ans = max(ans, sum);
            if(mp.find(currInd % k) != mp.end()){
                
                ans = max(ans, sum - mp[currInd % k]);
                mp[currInd % k] = min(mp[currInd % k], sum);
                
            }else mp[currInd % k] = sum;
        }
        return ans;
    }
};