class Solution {
    vector<int> fac[210]; 
    int n;
public:
    
    int num(string st) {
        int n = st.length();
        int ans = 1e9;

        for (auto it : fac[st.length()]) {
            int nu = n / it;
            int cur = 0;

            for (int i = 0; i < nu / 2; i++) {
                int i2 = nu - i - 1;
                for (int j = 0; j < it; j++)
                    if (st[i * it + j] != st[i2 * it + j])
                        cur++;
            }
            ans = min(ans, cur);
        }
        return ans;
    }
    
    int f(int i, int k, string &s, vector<vector<int>> &dp, vector<vector<int>> &pre){
        
        if(i == n){
            if(k == 0) return 0; 
            else return 1e9;
        }
        if(dp[i][k] != -1) return dp[i][k];
        
        int pick = 1e9;
        if(k > 0){
            for(int ind=i; ind<n; ind++){

                int x;
                if(pre[i][ind] != -1) x = pre[i][ind];
                else x = pre[i][ind] = num(s.substr(i, ind - i + 1));
                int cost = x + f(ind+1, k-1, s, dp, pre);
                pick = min(cost, pick);
            }
        }
        return dp[i][k] = pick;
    }
    
    int minimumChanges(string s, int k){
        
        this->n = s.size();
        for (int i = 2; i <= n; i++){
            for (int j = 1; j < i; j++){
                if (i % j == 0){
                    fac[i].push_back(j);
                }
            }
        }
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        vector<vector<int>> pre(n+10, vector<int> (n+10, -1));
        return f(0, k, s, dp, pre);
    }
};