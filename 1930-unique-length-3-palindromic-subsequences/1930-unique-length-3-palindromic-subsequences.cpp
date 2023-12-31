class Solution {
public:
    
    int countPalindromicSubsequence(string s) {
        
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<s.size(); i++){
            
            if(mp[s[i]].size() == 0){
                mp[s[i]].push_back(i);
                mp[s[i]].push_back(i);
            }else{
                mp[s[i]].back() = i;
            }
        }
        
        int ans = 0;
        for(auto i: mp){
            vector<int> temp = i.second;
            int x = temp[0];
            int y = temp[1];
            
            set<char> st;
            for(int j=x+1; j<y; j++){
                st.insert(s[j]);
            }
            ans += st.size();
        }
        return ans;
    }
};