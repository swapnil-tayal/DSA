class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        
        int n = s.size();
        vector<pair<char,int>> a;
        int i = 0;
        while(i < n){
            char ch = s[i];
            int cnt = 0;
            while(ch == s[i] and i < n){
                cnt++;
                i++;
            }
            a.push_back({ch, cnt});
        }
        int cnt = 0;
        for(auto i: s){
            cnt += i=='1';
        }
        int ans = cnt;
        for(int i=0; i<((int)a.size()-2); i++){
            if(a[i].first == '0' and a[i+1].first == '1' and a[i+2].first == '0'){
                ans = max(ans, cnt + a[i].second + a[i+2].second);
            }
        }
        return ans;
    }
};