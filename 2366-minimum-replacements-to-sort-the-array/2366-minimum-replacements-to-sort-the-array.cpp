class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 0) return 0;
        long long cnt = 0;
        
        for(int i=n-2; i>=0; i--){
            
            if(nums[i] > nums[i+1]){
                
                int k = ((nums[i] + nums[i+1]-1) / nums[i+1]);
                
                nums[i] = nums[i]/k;
                cnt += k-1;
                
                // cout<<nums[i]<<' '<<cnt<<'\n';
            }
        }
        return cnt;
    }
};