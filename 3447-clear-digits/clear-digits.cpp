class Solution {
public:
    string clearDigits(string s) {
        
        int n = s.size();
        stack<char> st;

        for(int i=0; i<n; i++){
            if(st.size() == 0) st.push(s[i]);
            else{
                if(s[i] >= '0' and s[i] <= '9'){
                    if(st.top() >= 'a' and st.top() <= 'z') st.pop();
                    else st.push(s[i]);
                }else{
                    st.push(s[i]);
                }
            }
        }
        string ans;
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        } 
        return ans;
    }
};