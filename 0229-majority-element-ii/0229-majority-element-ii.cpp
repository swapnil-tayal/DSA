class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int n = nums.size();
        
        int i = 0;
        while(i < n){
            
            int k = nums[i];
            if(k == nums[i]){
                
                int cnt = 0;
                while(i < n and nums[i] == k){
                    i++;
                    cnt++;
                }
                if(cnt > n/3) ans.push_back(k);
            }
        }
        return ans;
    }
};