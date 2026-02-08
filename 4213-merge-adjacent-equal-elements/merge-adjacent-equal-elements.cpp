class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        
        stack<long long> st;
        for(int i=0; i<nums.size(); i++){
            
            if(st.size() == 0) st.push(nums[i]);
            else{
                long long x = nums[i];
                while(st.size() && st.top() == x){
                    st.pop();
                    x = 2*x;
                }
                st.push(x);
            }
        }
        vector<long long> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};