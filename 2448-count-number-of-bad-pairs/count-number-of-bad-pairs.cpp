class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        long long n = nums.size();
        long long cnt = 0;
        map<int,int> mp;
        for(int i=0; i<n; i++){
            nums[i] = i - nums[i];
            mp[nums[i]]++;
        }
        for(auto &i: mp){
            long long x = i.second;
            cnt += x*(x-1)/2;
        }
        long long ans = (long long)(n*(n-1)/2) - cnt;
        return ans;
    }
};