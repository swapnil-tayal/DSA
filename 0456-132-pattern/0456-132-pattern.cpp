class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> minNum(n, -1);
        minNum[0] = nums[0];
        
        for(int i=1; i<n; i++){
            minNum[i] = min(minNum[i-1], nums[i]); 
        }
        
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            
            if(minNum[i] < nums[i]){
                
                while(!st.empty() and st.top() <= minNum[i]){
                    st.pop();
                }
                if(!st.empty() and st.top() < nums[i]) return 1;
                st.push(nums[i]);
            }
        }
        return 0;
    }
};