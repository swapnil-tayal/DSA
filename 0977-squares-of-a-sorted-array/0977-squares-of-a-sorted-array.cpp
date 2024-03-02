class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        vector<int> neg;
        vector<int> pos;
        
        int i = 0;
        int n = nums.size();
        while(i < n and nums[i] < 0){
            neg.push_back(nums[i]*nums[i]);
            i++;
        }
        while(i < n){
            pos.push_back(nums[i]*nums[i]);
            i++;
        }
        reverse(neg.begin(), neg.end());
        i = 0;
        int j = 0;
        vector<int> ans;
        while(i < neg.size() and j < pos.size()){
            
            if(neg[i] <= pos[j]) ans.push_back(neg[i++]);
            else ans.push_back(pos[j++]);
        }
        while(i < neg.size()) ans.push_back(neg[i++]);
        while(j < pos.size()) ans.push_back(pos[j++]);
        return ans;
    }
};