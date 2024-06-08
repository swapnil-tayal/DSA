class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        long long n = nums.size();
        if(n == 1) return 0;
        
        map<int,int> mp;
        mp[0] = 0;
        
        long long sum = 0;
        for(int i=0; i<n; i++){
            
            sum += nums[i];
            if(!mp.count(sum % k)) mp[sum % k] = i+1;
            else if(mp[sum % k] < i) return 1;
        }
        return 0;
    }
};