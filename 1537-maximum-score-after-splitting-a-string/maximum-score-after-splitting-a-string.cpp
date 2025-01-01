class Solution {
public:
    int maxScore(string s) {
        
        int cnt1 = 0;
        for(auto &i: s) cnt1 += (i=='1');
        int score = 0;
        int cnt0 = 0;
        int x = 0;
        for(auto &i: s){
            cnt0 += (i == '0');
            cnt1 -= (i == '1');
            if(x++ == s.size()-1) break;
            score = max(score, cnt0 + cnt1);
        }
        return score;
    }
};