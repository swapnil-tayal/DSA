class Solution {
    vector<string> ans;
public:
    
    void f(int i, int open, string &str){
        
        if(i == 0){
            if(open == 0)
            ans.push_back(str);
            return;
        }
        
        str += "(";
        f(i-1, open+1, str);
        str.pop_back();
        
        if(open >= 1){
            str += ")";
            f(i-1, open-1, str);
            str.pop_back();
        }
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        
        string str;
        f(2*n, 0, str);
        return ans;
    }
};