class Solution {
public:
    bool doesAliceWin(string s) {
        
        for(auto &i: s){
            if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u'){
                return 1;
            }
        }
        return 0;
    }
};