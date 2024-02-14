class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int> pos, neg;
        for(auto i: nums){
            if(i >= 0) pos.push_back(i);
            else neg.push_back(i);
        }
        vector<int> ans;
        int i = 0;
        int j = 0;
        for(int k=0; k<nums.size(); k++){
            if(k%2 == 0) ans.push_back(pos[i++]);
            else ans.push_back(neg[j++]);
        }
        return ans;
    }
};