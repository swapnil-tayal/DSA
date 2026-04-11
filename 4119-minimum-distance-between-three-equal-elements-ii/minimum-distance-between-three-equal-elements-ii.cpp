class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        
        int n = nums.size();
        map<int,vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        int ans = 1e9;
        for(auto &i: mp){
            if(i.second.size() > 2){
                for(int k=0; k<i.second.size()-2; k++){
                    ans = min(ans, 2*(i.second[k+2] - i.second[k]));
                }
            }
        }
        return ans == 1e9 ? -1 : ans;
    }
};