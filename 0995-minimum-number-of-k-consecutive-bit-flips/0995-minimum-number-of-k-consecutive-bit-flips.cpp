class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> rem(n, 0);
        
        int cnt = 0;
        int isRev = 0;
        for(int i=0; i<n; i++){
            
            if(rem[i]) isRev = 1 - isRev;
            if(isRev) nums[i] = 1 - nums[i];
            
            // if(i == 6) cout<<nums[i]<<' ';
            
            if(nums[i] == 0){
                cnt++;
                if(i+k < n){
                    rem[i+k] = 1;
                }else if(i+k > n) return -1;
                isRev = 1 - isRev;
                nums[i] = 1;
            
            }else continue;
        }
        for(auto i: nums){
            if(i == 0) return -1;
        }
        return cnt;
    }
};