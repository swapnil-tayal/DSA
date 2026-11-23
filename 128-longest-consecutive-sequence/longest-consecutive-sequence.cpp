class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        for(auto &i: nums) mp[i] = 0;

        int ans = 0;
        for(int i=0; i<nums.size(); i++){

            if(mp[nums[i]] == 1) continue;

            int val = nums[i]+1;
            int cnt = 1;
            while(mp.count(val) && mp[val] == 0){
                mp[val] = 1;
                cnt++;
                val = val+1;
            }
            val = nums[i]-1;
            while(mp.count(val) && mp[val] == 0){
                mp[val] = 1;
                cnt++;
                val = val-1;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};