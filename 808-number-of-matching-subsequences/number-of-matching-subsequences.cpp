class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        map<char, vector<int>> mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]].push_back(i);
        }
        int ans = 0;
        for(auto &str: words){
            int i = -1;
            int f = 0;
            for(auto &ch: str){
                if(mp[ch].size() == 0) f = 1;
                int ind = upper_bound(mp[ch].begin(), mp[ch].end(), i) - mp[ch].begin();
                if(ind == mp[ch].size()) f = 1;
                else i = mp[ch][ind];
            }
            if(f == 0){
                ans++;            
            }
        }
        return ans;
    }
};