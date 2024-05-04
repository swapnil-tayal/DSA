class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        
        long long sum = 0;
        int m = nums.size();
        int cnt = 0; 
        
        int i = 0;
        if(nums[0] != 1){
            nums.insert(nums.begin(), 1);
            cnt = 1;
            m++;
        }
        while(i < m){
            
            sum += nums[i];
            if(sum >= n) return cnt;
            
            if(i < m-1 and nums[i+1] > sum+1){
                
                while(sum < n and i < m-1 and nums[i+1] > sum+1){
                    sum += (sum+1);
                    cnt++;
                }
                if(sum >= n) return cnt;
            }
            i++;
        }
        while(sum < n){
            sum += (sum+1);
            cnt++;
        }
        return cnt;
    }
};