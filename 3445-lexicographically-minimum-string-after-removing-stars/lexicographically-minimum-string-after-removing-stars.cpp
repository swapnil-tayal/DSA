class Solution {
public:
    string clearStars(string s) {
        
        int n = s.size();
        map<char,vector<int>> mp;
        char ch = 'z';

        for(int i=0; i<n; i++){

            if(s[i] != '*'){
                mp[s[i]].push_back(i);
                ch = min(ch, s[i]);
            }
            else{
                s[mp[ch].back()] = '.';
                mp[ch].pop_back();
                if(mp[ch].size() == 0){
                    mp.erase(ch);
                    ch = 'z';
                    for(auto &k: mp) ch = min(ch, k.first);
                }   
            }
        }
        string res = "";
        for(auto &i: s){
            if(i == '.' || i == '*') continue;
            res += i;
        }
        return res;
    }
};