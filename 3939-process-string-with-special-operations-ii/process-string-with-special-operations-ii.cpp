class Solution {
public:
    char processStr(string s, long long k) {
        
        int n = s.size();
        long long len = 0;
        for(auto &ch: s){
            if(ch == '*') len = max(len-1, 0LL);
            else if(ch == '#') len = len * 2;
            else if(ch != '%') len++;
        }

        if(k >= len) return '.';

        for(int i=n-1; i>=0; i--){

            if(s[i] == '*') len++;
            else if(s[i] == '#'){

                if(k >= len/2) k = k -= (len/2);
                len = len / 2;

            }else if(s[i] == '%') k = len - 1 - k;
            else {
                if(len == k+1) return s[i];
                else len--;
            }
        }
        return '.';
    }
};