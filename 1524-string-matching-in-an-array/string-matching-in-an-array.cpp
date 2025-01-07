class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        
        set<string> st;
        int n = words.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<words[i].size(); j++){
                string s = "";
                for(int k=j; k<words[i].size(); k++){
                    s += words[i][k];
                    // cout<<s<<' ';
                    if(s != words[i]) st.insert(s);
                }
            }
        }
        // cout<<'\n';
        // for(auto i: st) cout<<i<<' ';
        vector<string> ans;
        for(auto i: words){
            if(st.count(i)) ans.push_back(i);
        }
        return ans;
    }
};