class Solution {
public:
    bool check(vector<int>& nums) {
        
        int n = nums.size();
        while(n--){
            if(is_sorted(nums.begin(), nums.end())) return 1;
            rotate(nums.begin(), nums.begin() + 1, nums.end());
        }
        return 0;
    }
};