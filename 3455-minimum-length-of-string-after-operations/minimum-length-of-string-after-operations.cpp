class Solution {
public:
    int minimumLength(string s) {
        
        map<int,int> mp;
        for(auto i: s) mp[i]++;

        int ans = 0;
        for(auto i: mp){
            if(i.second <= 2) ans += i.second;
            else if(i.second % 2) ans += 1;
            else ans += 2;
        }
        return ans;
    }
};