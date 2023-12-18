class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        
        for(int i=0; i<n; i++){
            
            if(i > 0 and nums[i] == nums[i-1]) continue;
            
            int j = i+1;
            int k = n-1;
            
            while(j < k){
                
                if(nums[j] + nums[k] + nums[i] < 0 || (j > i+1 and nums[j] == nums[j-1])){
                    j++;
                
                }else if(nums[j] + nums[k] + nums[i] > 0 || (k < n-1 and nums[k] == nums[k+1])){
                    k--;
                    
                }else{
                    ans.push_back({ nums[i], nums[j], nums[k] });
                    j++;
                    k--;
                }
            }
        }
        return ans;
    }
};