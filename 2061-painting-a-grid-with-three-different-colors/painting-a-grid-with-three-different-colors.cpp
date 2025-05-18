class Solution {
    vector<vector<int>> res;
    set<vector<int>> st;
    int mod = 1000000007;
public:
    void generateAllPossibleColumns(int i, int prev, int m, vector<int>& a) {
        if (i == m) {
            st.insert(a);
            return;
        }
        for (int v = 0; v < 3; ++v) {
            if (prev != -1 && v == prev) 
                continue;
            a.push_back(v);
            generateAllPossibleColumns(i+1, v, m, a);
            a.pop_back();
        }
    }
    bool check(vector<int> a1, vector<int> a2){
        int n = a1.size();
        for(int i=0; i<n; i++){
            if(a1[i] == a2[i]) return 0;
        }
        return 1;
    }

    void helper(int m){
        vector<int> a;
        generateAllPossibleColumns(0, -1, m, a);
        vector<vector<int>> arr(st.begin(), st.end());
        int n = arr.size();
        res.resize(n, vector<int>());
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(check(arr[i], arr[j])){
                    res[i].push_back(j);
                }
            }
        }
    }

    int f(int i, int prev, int n, vector<vector<int>> &dp){

        if(i == n) return 1;
        int ans = 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        if(prev == -1){
            for(int k=0; k<res.size(); k++){
                ans = (ans + f(i+1, k, n, dp)) % mod;
            }
        }else{
            for(int k=0; k<res[prev].size(); k++){
                ans = (ans + f(i+1, res[prev][k], n, dp)) % mod;
            }
        }
        return dp[i][prev+1] = ans;
    }

    int colorTheGrid(int m, int n) {
        
        helper(m);
        vector<vector<int>> dp(n, vector<int>(50, -1));
        return f(0, -1, n, dp);
    }
};