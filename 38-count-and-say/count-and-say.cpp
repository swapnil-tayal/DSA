class Solution {
public:

    void f(string &s, int n){

        if(n == 1) return;

        int x = s.size();
        int ind = 0;
        string str = "";
        while(ind < x){
            char ch = s[ind];
            int cnt = 0;
            while(ind < s.size() and s[ind] == ch){
                cnt++;
                ind++;
            }
            str += to_string(cnt) + ch;
        }
        s = str;
        f(s, n-1);
    }

    string countAndSay(int n) {
        
        string s = "1";
        if(n == 1) return s;
        f(s, n);
        return s;
    }
};