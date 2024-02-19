class Solution {
    int currMax = 0;
    set<string> ans;
public:
    
    void f(int i, string &s, string &str, int open){
        
        if(i == s.size()){
            if(open != 0) return;
            // cout<<str<<' ';
            if(str.size() > currMax){
                currMax = str.size();
                ans.clear();
                ans.insert(str);
            }else if(str.size() == currMax){
                ans.insert(str);
            }
            return;
        }
        
        if(s[i] != '(' and s[i] != ')'){
            str += s[i];
            f(i+1, s, str, open);
            str.pop_back();
        
        }else{
            
            f(i+1, s, str, open);
            if(s[i] == '('){
                str += '(';
                f(i+1, s, str, open+1);
                str.pop_back();
            }else if(open > 0){
                str += ')';
                f(i+1, s, str, open-1);
                str.pop_back();
            }
        }
        return;
    }
    
    vector<string> removeInvalidParentheses(string s) {
        
        int n = s.size();
        string str = "";
        f(0, s, str, 0);
        vector<string> res (ans.begin(), ans.end());
        return res;
    }
};