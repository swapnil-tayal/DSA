class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        
        set<string> st;
        for(auto &i: bannedWords){
            st.insert(i);
        }
        
        int cnt = 0;
        for(auto &i: message){
            if(st.count(i)){
                cnt++;
                if(cnt == 2) return 1;
            }
        }
        return 0;
    }
};