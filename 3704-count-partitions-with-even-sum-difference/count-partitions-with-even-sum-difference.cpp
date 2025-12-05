class Solution {
public:
    int countPartitions(vector<int>& nums) {
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int pre = 0;
        int ans = 0;
        if(sum % 2 == 0) ans--;
        for(auto i: nums){
            pre += i;
            if(abs(abs(pre - sum) - pre) % 2 == 0) ans++;
        }
        return ans;
    }
};