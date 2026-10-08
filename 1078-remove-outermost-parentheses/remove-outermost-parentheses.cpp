class Solution {
public:
    string removeOuterParentheses(string s) {
        
        int sum = 0;
        string str = "";
        string res = "";

        for(auto &i: s){

            if(i == '(') sum++;
            else sum--;
            str += i;
            if(sum == 0){
                res += str.substr(1, str.size()-2);
                str = "";
            }
        }
        return res;
    }
};