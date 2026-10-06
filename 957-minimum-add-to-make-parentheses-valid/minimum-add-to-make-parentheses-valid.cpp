class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int cnt = 0;
        int close = 0;
        int open = 0;
        int n = s.size();
        for(auto &i: s){
            if(i == ')') close++;
            else open++;
            if(i == ')' and close > open){
                cnt += close - open;
                close = 0;
                open = 0;
            }
        }
        cnt += abs(open - close);
        return abs(cnt);
    }
};