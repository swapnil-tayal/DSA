class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        int n = s.size();
        map<char,int> mp;
        for(int i=0; i<n; i++){
            mp[s[i]] = i;
        }
        
        stack<char> st;
        vector<int> vis(26, 0);
        
        for(int i=0; i<n; i++){
            
            if(vis[s[i]-'a']) continue;
            if(st.size() == 0 || st.top() < s[i]){
                
                st.push(s[i]);
                vis[s[i] - 'a'] = 1;
                
            }else{
                
                
                while(!st.empty() and st.top() > s[i]){
                    
                    int ind = mp[st.top()];
                    if(ind > i){
                        
                        vis[st.top()-'a'] = 0;
                        st.pop();
                    
                    }else break;
                }
                st.push(s[i]);
                vis[s[i]-'a'] = 1;
            }
        }
        string str;
        while(!st.empty()){
            str = st.top() + str;
            st.pop();
        }
        return str;
    }
};