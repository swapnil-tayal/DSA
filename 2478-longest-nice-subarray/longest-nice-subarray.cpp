class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 1;
        int i = 0;
        int j = 0;
        int val = 0;

        while(j < n){
            
            while((val & nums[j]) != 0){
                val = val ^ nums[i];
                i++;
            }
            val = val | nums[j];
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};