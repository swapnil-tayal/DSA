class Solution {
public:
    bool parseBoolExpr(string s) {
        
        int n = s.size();
        int ans;
        char opr;
        
        stack<char> st;
        for(int i=0; i<n; i++){
            
            if(s[i] == ',') continue;
            if(s[i] == ')'){
                
                string str = "";
                while(st.top() != '('){
                    str += st.top();
                    st.pop();
                }
                st.pop();
                
                int exp = -1;
                if(st.top() == '|'){
                    for(auto &k: str){
                        if(exp == -1) exp = (k=='t' ? true : false);
                        else exp = exp | (k=='t' ? true : false);
                    }
                } 
                else if(st.top() == '&'){
                    for(auto &k: str){
                        if(exp == -1) exp = (k=='t' ? true : false);
                        else exp = exp & (k=='t' ? true : false);
                    }
                }else exp = (str[0]=='t' ? false : true);
                
                st.pop();
                st.push((exp == 1 ? 't' : 'f'));
                
            }else st.push(s[i]);
        }
        return st.top() == 't' ? 1 : 0;
    }
};