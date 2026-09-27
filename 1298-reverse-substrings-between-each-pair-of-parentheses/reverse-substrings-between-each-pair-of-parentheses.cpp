class Solution {
public:
    string reverseParentheses(string s) {
        
        stack<char> st;
        int cnt = 0;
        for(auto &ch: s){

            if(ch == ')'){

                string str = "";
                while(st.top() != '('){
                    str += st.top();
                    st.pop();
                }
                st.pop();
                for(auto &k: str) st.push(k);
            
            } else st.push(ch);
        }
        string str = "";
        while(!st.empty()){
            str += st.top();
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};