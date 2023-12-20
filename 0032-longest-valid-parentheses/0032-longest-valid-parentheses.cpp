class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<int> st;
        int n = s.size();
        int ans = 0;
        
        for(int i=0; i<n; i++){
            
            if(st.empty()) st.push(i);
            else{
                if(s[st.top()] == '(' and s[i] == ')') st.pop();
                else st.push(i);
            }
            if(st.empty()) ans = max(ans, i+1);
            else ans = max(ans, i - st.top());
        }
        return ans;
    }
};