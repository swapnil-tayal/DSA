class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
        map<int,vector<int>> mp;
        int n = nums.size();
        
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<nums[i].size(); j++){
                mp[cnt+j].push_back(nums[i][j]);
            }cnt++;   
        }
        for(auto &i: mp) reverse(i.second.begin(), i.second.end());
        vector<int> ans;
        for(auto i: mp){
            for(auto j: i.second) ans.push_back(j);
        }
        return ans;
    }
};