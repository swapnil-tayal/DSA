class Solution {
public:
    bool canBeValid(string s, string locked) {
        
        if(s.size() % 2) return 0;
        
        int openCnt = 0;
        for(int i=0; i<s.size(); i++){
            if(locked[i] == '0' || s[i] == '(') openCnt++;
            else openCnt--;
            if(openCnt < 0) return 0;
        }
        openCnt = 0;
        for(int i=s.size()-1; i>=0; i--){
            if(locked[i] == '0' || s[i] == ')') openCnt++;
            else openCnt--;
            if(openCnt < 0) return 0;
        }
        return 1;
    }
};