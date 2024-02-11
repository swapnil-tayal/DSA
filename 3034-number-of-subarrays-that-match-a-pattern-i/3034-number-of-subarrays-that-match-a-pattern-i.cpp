class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        
        int n = nums.size();
        int m = pattern.size();
        int cnt = 0;
        
        for(int i=0; i<n-m; i++){
            
            int f = 0;
            for(int j=0; j<m; j++){
                
                if(pattern[j] == 1 and nums[i+j] >= nums[i+j+1]) f = 1;
                if(pattern[j] == 0 and nums[i+j] != nums[i+j+1]) f = 1;
                if(pattern[j] == -1 and nums[i+j] <= nums[i+j+1]) f = 1;
            }
            if(f == 0) cnt++;
        }
        return cnt;
    }
};