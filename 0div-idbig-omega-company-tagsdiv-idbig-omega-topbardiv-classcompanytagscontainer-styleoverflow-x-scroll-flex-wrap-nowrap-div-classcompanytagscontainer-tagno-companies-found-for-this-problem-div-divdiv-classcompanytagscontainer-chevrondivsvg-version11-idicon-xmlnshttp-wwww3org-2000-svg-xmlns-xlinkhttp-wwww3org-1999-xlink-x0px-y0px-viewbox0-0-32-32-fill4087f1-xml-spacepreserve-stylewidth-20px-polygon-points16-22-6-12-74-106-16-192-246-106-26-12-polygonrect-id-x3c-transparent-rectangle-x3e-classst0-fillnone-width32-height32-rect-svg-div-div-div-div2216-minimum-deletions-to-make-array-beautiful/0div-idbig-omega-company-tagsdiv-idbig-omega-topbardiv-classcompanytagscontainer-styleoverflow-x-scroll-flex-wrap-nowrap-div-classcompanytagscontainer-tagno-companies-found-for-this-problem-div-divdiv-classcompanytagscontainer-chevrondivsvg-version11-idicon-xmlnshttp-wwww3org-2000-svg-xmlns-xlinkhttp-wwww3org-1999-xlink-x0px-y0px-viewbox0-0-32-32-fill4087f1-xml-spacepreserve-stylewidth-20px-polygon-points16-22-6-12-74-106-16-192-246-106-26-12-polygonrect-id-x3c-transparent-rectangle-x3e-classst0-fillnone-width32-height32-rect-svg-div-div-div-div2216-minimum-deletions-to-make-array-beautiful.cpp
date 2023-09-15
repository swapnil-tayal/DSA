class Solution {
public:
    int minDeletion(vector<int>& nums) {
        
        stack<int> st;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(st.size() == 0) st.push(nums[i]);
            else{
                if(st.size()%2 == 1){
                    if(st.top() != nums[i]) st.push(nums[i]);
                
                }else st.push(nums[i]);
            }
        }
        if(st.size()%2) st.pop();
        return n - st.size();
    }
};