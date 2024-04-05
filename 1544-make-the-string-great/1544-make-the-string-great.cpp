class Solution {
public:
    string makeGood(string s) {
        
        int n = s.size();
        stack<char> st;
        
        for(auto &i: s){    
            if(st.size() == 0) st.push(i);
            else{
                if(i >= 'A' and i <= 'Z'){
                    
                    char ch = tolower(i);
                    if(ch == st.top()) st.pop();
                    else st.push(i);
                }else{
                    
                    char ch = toupper(i);
                    if(ch == st.top()) st.pop();
                    else st.push(i);
                }
            }
        }
        string str = "";
        while(!st.empty()){
            str = st.top() + str;
            st.pop();
        }
        return str;
    }
};