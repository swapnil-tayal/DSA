class Solution {
public:
    int countWays(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int cnt = 0;
        cnt = (nums[0] != 0);
        
        for(int i=0; i<n; i++){
            
            if(i+1 > nums[i]){
                if(i+1 < n and nums[i+1] > i+1) cnt++;
                else if(i+1 == n) cnt++;
            }
        }
        return cnt;
    }
};