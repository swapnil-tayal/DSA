class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        int n = nums.size();
        int x = nums[0];
        int allZero = (nums[0] == 0);
        for(int i=1; i<n; i++){
            if(nums[i] != 0) allZero = 0;
            x = x ^ nums[i];
        }
        if(allZero) return 0;
        if(x == 0) return n-1;
        else return n; 
    }
};
