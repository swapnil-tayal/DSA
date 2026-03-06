class Solution {
    int target;
    vector<string> ans;

public:
    void f(int i, string &num, const string &str, long long rem, long long curr){

        if(i == num.size()){
            if(curr == target) ans.push_back(str);
            return;
        }
        
        long long digit = 0;
        string currStr;
        for(int k=i; k<num.size(); k++){
            if(k > i and num[i] == '0') return;
            currStr += num[k];
            digit = digit*10 + (num[k]-'0');
            if(i == 0){
                f(k+1, num, str + currStr, digit, digit);
            }else{
                f(k+1, num, str + "+" + currStr, digit, curr + digit);
                f(k+1, num, str + "-" + currStr, -digit, curr - digit);
                f(k+1, num, str + "*" + currStr, rem * digit, curr - rem + rem * digit);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        this->target = target;
        f(0, num, "", 0, 0);
        return ans;
    }
};