class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
        for(auto &i: tokens){
            
            if(i[0] >= '0' and i[0] <= '9' or (i[0]=='-' and i.size() > 1)) st.push(stoi(i));
            else{
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                
                if(i == "+") st.push(num1+num2);
                else if(i == "-") st.push(num2-num1);
                else if(i == "/") st.push(num2/num1);
                else st.push(num1*num2);
            }
        }
        return st.top();
    }
};