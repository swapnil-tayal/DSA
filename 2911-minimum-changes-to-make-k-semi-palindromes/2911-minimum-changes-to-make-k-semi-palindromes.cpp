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
    
    int f(int i, int prev, int k, string &s, vector<vector<vector<int>>> &dp, vector<vector<int>> &pre){
        
        if(i == n){
            if(k == 0 and prev != n){
                if(pre[prev][i-1] != -1) return pre[prev][i-1];
                else return pre[prev][i-1] = num(s.substr(prev, i - prev + 1));
            }
            else return 1e9;
        }
        if(dp[i][prev][k] != -1) return dp[i][prev][k];
        
        int npick = f(i+1, prev, k, s, dp, pre);
        int pick = 1e9;
        if(k > 0){
            int x;
            if(pre[prev][i] != -1) x = pre[prev][i];
            else x = pre[prev][i] = num(s.substr(prev, i - prev + 1));
            pick = x + f(i+1, i+1, k-1, s, dp, pre);
        }
        return dp[i][prev][k] = min(pick, npick);
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
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k, -1)));
        vector<vector<int>> pre(n+10, vector<int> (n+10, -1));
        return f(0, 0, k-1, s, dp, pre);
    }
};