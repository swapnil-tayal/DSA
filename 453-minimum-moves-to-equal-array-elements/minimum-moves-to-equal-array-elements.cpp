class Solution {
public:
    int minMoves(vector<int>& nums) {

        int n = nums.size();
        if(n == 1) return 0;
        sort(nums.begin(), nums.end());

        int ans = 0;
        while(nums[0] != nums[n-1]){

            int diff = nums[n-1] - nums[0];
            nums[n-2] += ans + diff;
            nums.insert(nums.begin(), nums[n-1]);
            nums.pop_back();
            ans += diff;
        }
        return ans;
    }
}; 

// 1 3 5 9
// +8
// 9 11 13 9
// 9 9 13 13
// 9 1 12 13