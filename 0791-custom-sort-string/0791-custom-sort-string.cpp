class Solution {
public:
    string customSortString(string order, string s) {
        
        map<char,int> mp;
        for(auto i: s) mp[i]++;
        
        string ans = "";
        for(auto i: order){
            
            int x = mp[i];
            while(x--) ans += i;
            mp[i] = 0;
        }
        
        for(auto i: s){
            if(mp[i]) ans += i;
        }
        return ans;
    }
};