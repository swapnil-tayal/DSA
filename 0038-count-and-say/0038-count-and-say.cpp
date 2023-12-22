class Solution {
public:
    
    string f(int n){
        
        if(n == 1) return "1";
        string s = f(n-1);
        string str = "";
        int len = s.size();
        int i = 0;
        while(i < len){
            char k = s[i];
            int cnt = 0;
            while(i<len and s[i] == k){
                cnt++;
                i++;
            }
            str += to_string(cnt);
            str += k;
        }
        return str;
    }
    
    string countAndSay(int n) {
        return f(n);
    }
};