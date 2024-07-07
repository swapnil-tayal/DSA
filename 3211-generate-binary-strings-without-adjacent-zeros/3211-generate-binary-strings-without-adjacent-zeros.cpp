class Solution {
    vector<string> ans;
public:
    
    void f(int i, char prev, string &str){
        
        if(i == 0){
            ans.push_back(str);
            return;
        }
        
        if(prev == '-1' || prev == '1'){
            
            str += "0";
            f(i-1, '0', str);
            str.pop_back();
            str += "1";
            f(i-1, '1', str);
            str.pop_back();
            
        }else{
            
            str += "1";
            f(i-1, '1', str);
            str.pop_back();
            
        }
        return;
    }
    
    vector<string> validStrings(int n) {
        
        string str = "";
        f(n, '-1', str);
        return ans;
    }
};