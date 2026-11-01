class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int bestSum = -1e9;
        int currSum = 0;
        for(auto &i: nums){

            currSum = max(i, currSum + i);
            bestSum = max(bestSum, currSum);
        }
        return bestSum;
    }
};