class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        map<int,int> mp;
        int n = nums.size();
        int sum = 0;
        mp[0] = 1;
        int cnt = 0;
        
        for(int i=0; i<n; i++){
            
            sum += nums[i];
            if(mp.find(sum - k) != mp.end()){
                cnt += mp[sum-k];
            }
            mp[sum]++;
        }
        return cnt;
    }
};