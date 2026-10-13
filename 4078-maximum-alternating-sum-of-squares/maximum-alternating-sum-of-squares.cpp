class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        
        for(auto &i: nums) i = abs(i);
        
        sort(nums.rbegin(), nums.rend());
        long long sum = 0;
        int n = nums.size();
        
        for(int i=0; i<n; i++){

            if(i < (n+1)/2) sum += nums[i] * nums[i];
            else sum -= nums[i] * nums[i];
        }
        return sum;
    }
};