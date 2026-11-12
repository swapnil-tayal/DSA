class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int cnt = 0;
        int last = 0;
        int n = nums.size();
        int ans = 1;
        int prev = 0;

        for(int i=1; i<n; i++){

            if(nums[i] > nums[i-1]){
                if(last == 1) prev++;
                else prev = 2;
                last = 1;
            }else if(nums[i] < nums[i-1]){
                if(last == -1) prev++;
                else prev = 2;
                last = -1;
            }else{
                last = 0;
                prev = 0;
            }
            ans = max(ans, prev);
        }
        return ans;
    }
};