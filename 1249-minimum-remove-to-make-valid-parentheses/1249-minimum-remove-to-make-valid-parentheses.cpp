class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int n = s.size();
        vector<pair<char,int>> paraOnly;
        
        for(int i=0; i<n; i++){ 
            if(s[i] == '(' || s[i] == ')'){
                paraOnly.push_back({ s[i], i }); 
            }
        }
        string validStr = "";
        stack<pair<char,int>> st;
        set<int> stt;
        
        for(auto i: paraOnly){
            
            if(st.size() == 0){
                if(i.first == ')') stt.insert(i.second);
                else st.push({ i.first, i.second });
                
            }else if(i.first == '('){
                st.push({ i.first, i.second });
                
            }else{
                if(st.top().first == '(') st.pop();
            }
        }
        while(!st.empty()){
            stt.insert(st.top().second);
            st.pop();
        }
        string ans = "";
        for(int i=0; i<n; i++){
            if(stt.count(i)) continue;
            else ans += s[i];
        }
        return ans;
    }
};