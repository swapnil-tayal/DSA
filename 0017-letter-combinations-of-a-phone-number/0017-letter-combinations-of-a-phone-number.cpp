class Solution{
    vector<string> arr;
    vector<string> ans;
public:
    
    void f(int i, string &digit, string &str){
        
        if(i == digit.size()){
            ans.push_back(str);
            return;
        }
        
        string s = arr[digit[i]-'0'];
        for(auto &k: s){
            str += k;
            f(i+1, digit, str);
            str.pop_back();
        }
        return;
    }
    
    vector<string> letterCombinations(string digits) {
        
        if(digits.size() == 0) return {};
        
        arr.resize(10);
        arr[0] = "";
        arr[2] = "abc";
        arr[3] = "def";
        arr[4] = "ghi";
        arr[5] = "jkl";
        arr[6] = "mno";
        arr[7] = "pqrs";
        arr[8] = "tuv";
        arr[9] = "wxyz";
        string str;
        f(0, digits, str);
        return ans;
    }
};