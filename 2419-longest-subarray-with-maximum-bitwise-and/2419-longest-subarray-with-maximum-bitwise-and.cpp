class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        
        int sx = 0;
        int i = 0;
        while(i < n){
            
            if(nums[i] == maxi){
                int cnt = 0;
                while(i < n and nums[i] == maxi){
                    cnt++;
                    i++;
                }
                sx = max(sx, cnt);
            }else i++;
        }
        return sx;
    }
};