class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> a;
        for(int i=1; i<=n; i++){
            a.push_back(to_string(i));
        }
        sort(a.begin(), a.end());
        
        vector<int> ans;
        for(auto &i: a){
            ans.push_back(stoi(i));
        }
        return ans;
    }
};