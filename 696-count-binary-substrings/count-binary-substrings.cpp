class Solution {
public:
    int countBinarySubstrings(string s) {
        
        vector<int> a;
        int i = 0;
        int n = s.size();
        while(i < n){
            char ch = s[i];
            int cnt = 0;
            while(ch == s[i]){
                cnt++;
                i++;
            }
            a.push_back(cnt);
        }
        int ans1 = 0;
        int ans2 = 0;
        for(int i=0; i<a.size()-1; i++){
            if(i%2 == 0) ans1 += min(a[i], a[i+1]);
            else ans2 += min(a[i], a[i+1]);
        }
        return ans1 + ans2;
    }
};