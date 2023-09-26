class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        int n = s.size();
        map<char, vector<int>> mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]].push_back(i);
        }
        
        vector<int> vis(26, 0); 
        stack<int> st;
        string ans;
        
        for(int i=0; i<n; i++){
            
            if(vis[s[i]-'a'] == 1) continue;
            
            if(st.size() == 0){
                st.push(s[i]);
                vis[s[i]-'a'] = 1;
            }
            else{
                
                if(st.top() == s[i]) continue;
                else if(st.top() < s[i]){
                    st.push(s[i]);
                    vis[s[i]-'a'] = 1;
                }
                else{
                    
                    while(!st.empty() and st.top() > s[i]){
                        
                        char ch = st.top();
                        int ind = mp[ch].back();
                        
                        if(ind > i){
                            vis[st.top()-'a'] = 0;
                            st.pop();
                        }
                        else break;
                    }
                    st.push(s[i]);
                    vis[s[i]-'a'] = 1;
                }
            }
        }
        string str;
        while(!st.empty()){
            string temp;
            temp += st.top();
            temp += str;
            str = temp;
            st.pop();
        }
        return str;
    }
};