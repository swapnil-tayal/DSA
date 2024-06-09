class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        int sum = 0;
        int cnt = 0;
        mp[0]++;
        
        for(auto i: nums){
            
            sum += i;
            int rem = sum % k;
            if(rem < 0) rem += k;
            if(mp.count(rem)){
                cnt += mp[rem];
            }
            mp[rem]++;
        }
        return cnt;
    }
};