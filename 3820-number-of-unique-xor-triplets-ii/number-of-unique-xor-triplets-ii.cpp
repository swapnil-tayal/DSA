class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        
        int n = nums.size();
        unordered_set<int> st;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                st.insert(nums[i] ^ nums[j]);
            }
        }
        unordered_set<int> ans;
        for(auto &i: st){
            for(int k=0; k<n; k++){
                ans.insert(i ^ nums[k]);
            }
        }
        return ans.size();
    }
};

