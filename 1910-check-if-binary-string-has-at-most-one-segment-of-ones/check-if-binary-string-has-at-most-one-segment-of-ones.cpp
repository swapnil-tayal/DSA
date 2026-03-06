class Solution {
public:
    bool checkOnesSegment(string s) {
        
        int n = s.size();
        int i = 0;
        int cnt = 0;
        while(i < n){
            char ch = s[i];
            while(i < n and ch == s[i]){
                i++;
            }
            if(ch == '1'){
                cnt++;
                if(cnt > 1) return 0;
            }
        }
        return 1;
    }
};