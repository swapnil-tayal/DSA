class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        
        long long sum = 0;
        for(auto &i: nums) sum += i;
        long long s = 0;
        int cnt = 0;
        for(int i=0; i<nums.size()-1; i++){
            s += nums[i];
            if(sum-s <= s) cnt++;
        }
        return cnt;
    
    }
};