class Solution {
public:
    bool canConstruct(string s, int k) {
        
        int n = s.size();
        unordered_map<char,int> mp;

        for(auto &i: s) mp[i]++;
        int cnt = 0;
        for(auto &i: mp){
            if(i.second % 2 == 1) cnt++;
        }
        return (s.size() >= k) && (cnt <= k);
    }
};