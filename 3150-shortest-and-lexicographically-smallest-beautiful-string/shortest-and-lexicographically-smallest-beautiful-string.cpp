class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        
        int n = s.size();
        string ans = string(n ,'1');
        int flag = 0;
        for(int i=0; i<n; i++){
            string str = "";
            int cnt1 = 0;
            for(int j=i; j<n; j++){
                cnt1 += (s[j] == '1');
                str += s[j];
                if(cnt1 == k){
                    flag = 1;
                    if(str.size() < ans.size()) ans = str; 
                    else if(str.size() == ans.size()) ans = min(ans, str);
                }
            }
        }
        if(flag == 0) return "";
        return ans;
    }
};