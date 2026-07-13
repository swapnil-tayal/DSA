class Solution {
    int n;
    int low;
    int high;
    set<int> ans;
public:
    
    void f(int i, string str){
        
        if(i == n){
            if(str.size() == 0) return;
            int k = stoi(str);
            if(k >= low and k <= high){
                ans.insert(k);
            }
            return;
        }
        
        if(str.size() == 0){
            f(i+1, str);
            for(char ch='0'; ch<='9'; ch++){
                str += ch;
                f(i+1, str);
                str.pop_back();
            }
        }else{
            if(char(str.back()+1) <= '9'){
                str += char(str.back()+1);
                f(i+1, str);
                str.pop_back();
            }
        }
    }
    
    vector<int> sequentialDigits(int low, int high) {
        
        n = to_string(high).size();
        this->low = low;
        this->high = high;
        string str = "";
        f(0, str);
        vector<int> res (ans.begin(), ans.end());
        return res;
    }
};