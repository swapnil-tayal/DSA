class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        int m = l.size();
        int n = nums.size();
        
        vector<bool> ans(m);
        
        for(int i=0; i<m; i++){
            
            vector<int> temp;
            for(int j=l[i]; j<=r[i]; j++){
                temp.push_back(nums[j]);
            }
            sort(temp.begin(), temp.end());
            int diff = -1;
            bool val = true;
            
            // for(auto j: temp) cout<<j<<' ';
            // cout<<'\n';
            
            for(int j=0; val and j<temp.size()-1; j++){
                if(diff == -1) diff = temp[j+1] - temp[j];
                else if(diff != temp[j+1] - temp[j]){
                    val = false;
                }
            }
            ans[i] = val;
        }
        return ans;
    }
};