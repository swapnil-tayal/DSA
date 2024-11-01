class Solution {
public:
    string makeFancyString(string s) {
        
        int n = s.size();
        int i = 0;
        string ans = "";
        
        while(i < n){
            
            int cnt = 0;
            char ch = s[i];
            while(i<n && s[i] == ch){
                cnt++;
                i++;
            }
            for(int k=0; k<min(cnt, 2); k++){
                ans += ch;
            }
        }
        return ans;
    }
};