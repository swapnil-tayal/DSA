class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        
        int n = nums.size();
        
        map<int,long long> mp;
        long long ans = 0;
        int cnt = 0;
        mp[0] = 1;
        
        for(int i=0; i<n; i++){
            
            if(nums[i] % mod == k) cnt++;
            
            // cout<<(cnt - k + mod) % mod<<' ';
            
            ans += mp[(cnt - k + mod) % mod];
            mp[cnt % mod]++;
        }
        return ans;
    }
};