class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            
            if(i > 0 and nums[i] == nums[i-1]) continue;
            for(int j=i+1; j<n; j++){
                
                if(j > i+1 and nums[j] == nums[j-1]) continue;
                int x = j+1;
                int y = n-1;
                long long sm = nums[i] + nums[j];
                
                while(x < y){
                    
                    if(sm + nums[x] + nums[y] < target || (x > j+2 and nums[x] == nums[x-1])){
                        x++;
                    }
                    else if(sm + nums[x] + nums[y] > target || (y < n-1 and nums[y] == nums[y+1])){
                        y--;
                    }
                    else{
                        
                        ans.push_back({nums[i], nums[j], nums[x], nums[y]});
                        int t = nums[x];
                        int t2 = nums[y];
                        y--;
                        x++;
                    }
                }
            }
        }
        // vector<vector<int>> res (ans.begin(), ans.end());
        return ans;
    }
};