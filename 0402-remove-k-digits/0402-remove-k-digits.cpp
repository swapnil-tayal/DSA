class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int n = num.size();
        stack<int> st;
        
        if(k == 0) return num;
        
        for(int i=0; i<n; i++){
            
            int x = (num[i] - '0');
            
            if(k == 0){
                st.push(x);
                continue;
            }
            
            if(st.size() == 0){
                st.push(x);
            }
            else{
                while(st.size() and st.top() > x and k){
                    k--;
                    st.pop();
                }
                st.push(x);
            }
        }
        num = "";
        
        while(k and st.size()){
            st.pop();
            k--;
        }
        
        while(!st.empty()){
            num += char(st.top() + '0');
            st.pop();
        }
        
        while(num.size() and num.back() == '0') num.pop_back();
        reverse(num.begin(), num.end());
        if(num.size() == 0) return "0";
        return num;
    }
};