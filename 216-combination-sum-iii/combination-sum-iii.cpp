class Solution {
public:

    void f(int ind, int k, int n, int currValue, vector<int> &a, vector<vector<int>> &ans){
        
        if(ind == 0 || k <= 0){
            if(currValue == n and k == 0) ans.push_back(a);
            return;
        }

        a.push_back(ind);
        f(ind-1, k-1, n, currValue + ind, a, ans);
        a.pop_back();
        f(ind-1, k, n, currValue, a, ans);
        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> a;
        vector<vector<int>> ans;
        f(9, k, n, 0, a, ans);
        return ans;
    }
};