class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        int n = s.size();
        map<char, vector<int>> mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]].push_back(i);
        }
        // for(auto i: mp['d']) cout<<i<<' ';
        
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
                    
                    if(i == 5) cout<<(char)st.top()<<' ';
                    
                    while(!st.empty() and st.top() > s[i]){
                        char ch = st.top();
                        int ind = upper_bound( mp[ch].begin(), mp[ch].end(), i ) - mp[ch].begin();

                        // if(i == 5){
                            // cout<<ind<<' '<<ch<<' ';
                        // }
                        if(ind != mp[ch].size()){
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
            str += st.top();
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};