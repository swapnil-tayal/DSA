class Solution {
    
    vector<vector<string>> ans;
    bool isPalidrome(int start, int end, string s){
        
        while(start <= end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
public:
    
    void f(int i, string s, vector<string> &temp){
        
        if(i == s.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int k=i; k<s.size(); k++){
            
            if(isPalidrome(i, k, s)){
                
                // cout<<i<<" "<<k-i+1<<" "<<s.substr(i, k)<<"\n";
                
                temp.push_back(s.substr(i, k-i+1));
                f(k+1, s, temp);
                temp.pop_back();
            }
        }return;
    }
    
    vector<vector<string>> partition(string s) {
        
        int n = s.size();
        vector<string> temp;
        f(0, s, temp);
        return ans;
    }
};