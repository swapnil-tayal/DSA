class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        map<char, vector<int>> mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]].push_back(i);
        }
        int ans = 0;
        set<string> st;
        for(auto &str: words){
            int i = -1;
            int f = 0;
            if(st.count(str)){
                ans++;
                continue;
            }
            for(auto &ch: str){
                vector<int> a = mp[ch];
                if(a.size() == 0) f = 1;
                int ind = upper_bound(a.begin(), a.end(), i) - a.begin();
                if(ind == a.size()) f = 1;
                else i = a[ind];
            }
            if(f == 0){
                ans++;            
                st.insert(str);
            }
        }
        return ans;
    }
};