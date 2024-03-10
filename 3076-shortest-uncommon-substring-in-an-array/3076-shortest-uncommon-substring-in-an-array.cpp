class Solution {
    unordered_map<int, set<string>> mp;
public:
    
    void f(vector<string> &arr){
        
        int n = arr.size();
        for(int i=0; i<n; i++){
            
            for(int k=0; k<arr[i].size(); k++){
                string sub = "";
                for(int l=k; l<arr[i].size(); l++){
                    sub += arr[i][l];
                    mp[i].insert(sub);
                }
            }
        }
    }
    
    int f2(string &str, int ind){
        
        for(auto &i: mp){
            
            if(i.first == ind) continue;
            if(i.second.count(str) != 0) return 0;
        }
        return 1;
    }
    
    vector<string> shortestSubstrings(vector<string>& arr) {
        
        int n = arr.size();
        vector<string> ans(n, "");
        f(arr);
        
        for(int i=0; i<n; i++){
            
            string sub = "";
            for(int k=0; k<arr[i].size(); k++){
                string str = "";
                for(int l=k; l<arr[i].size(); l++){
                    
                    str += arr[i][l];
                    if(f2(str, i)){
                        if(sub.size() == 0) sub = str;
                        else if(sub.size() > str.size()) sub = str;
                        else if(sub.size() == str.size()) sub = min(sub, str);
                    }
                }
            }
            ans[i] = sub;
        }
        return ans;
    }
};