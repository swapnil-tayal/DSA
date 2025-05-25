class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        map<string,int> mp;
        for(auto &i: words) mp[i]++;
        int ans = 0;
        int f = 0;
        for(auto &i: mp){

            string s1 = i.first;
            string s2;
            s2 += s1[1];
            s2 += s1[0];
            int cnt = min(mp[s1], mp[s2]);
            if(s1 != s2){
                ans += 4*cnt;
                mp[s1] = 0;
                mp[s2] = 0;
            }
            if(s1 == s2){
                cout<<s1<<' '<<mp[s1]<<'\n';
                if(mp[s1] > 1){
                    ans += 4*(mp[s1]/2);
                    if(mp[s1] % 2) f = 1;
                }else f = 1;
            }
        }
        // ans /= 2;
        if(f) ans += 2;
        return ans;
    }
};