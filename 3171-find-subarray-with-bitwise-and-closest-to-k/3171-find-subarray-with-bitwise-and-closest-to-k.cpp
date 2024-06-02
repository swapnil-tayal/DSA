class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        
        set<int> prev;
        int ans = 1e9;
        for(auto i: nums){
            
            set<int> curr;
            for(auto x: prev){
                curr.insert(x & i);
            }curr.insert(i);
            
            for(auto x: curr){
                ans = min(ans, abs(x-k));
            }
            prev = curr;
        }
        return ans;
    }
};