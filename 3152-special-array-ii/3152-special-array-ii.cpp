class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        
        // 0 1 2 3 4 5 6 7
        //  0 1 2 3 4 5 6
            
        int n = nums.size();
        vector<int> opr;
        for(int i=0; i<n-1; i++){
            
            int x = (opr.size() ? opr.back() : 0) + ((nums[i]%2) == (nums[i+1]%2));
            opr.push_back(x);
            
        }
        vector<bool> ans;
        for(auto i: queries){
            
            int ind1 = i[0];
            int ind2 = i[1];
            
            if(ind1 == ind2){
                ans.push_back(true);
                continue;
            }
            int sm = opr[ind2-1];
            if(ind1 > 0) sm -= opr[ind1-1];
            if(sm == 0) ans.push_back(true);
            else ans.push_back(false);
            
        }
        return ans;
    }
};