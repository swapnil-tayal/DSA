class Solution {
    vector<vector<int>> res;
    set<vector<int>> st;
public:
    void f(int i, int prev, int m, vector<int> &a){
        if(i == m){
            st.insert(a);
            return;
        }   
        if(prev == -1){
            a.push_back(0);
            f(i+1, 0, m, a);
            a.pop_back();
            a.push_back(1);
            f(i+1, 1, m, a);
            a.pop_back();
            a.push_back(2);
            f(i+1, 2, m, a);
            a.pop_back();
        }if(prev == 0){
            a.push_back(1);
            f(i+1, 1, m, a);
            a.pop_back();
            a.push_back(2);
            f(i+1, 2, m, a);
            a.pop_back();
        }else if(prev == 1){
            a.push_back(0);
            f(i+1, 0, m, a);
            a.pop_back();
            a.push_back(2);
            f(i+1, 2, m, a);
            a.pop_back();
        }else{
            a.push_back(0);
            f(i+1, 0, m, a);
            a.pop_back();
            a.push_back(1);
            f(i+1, 1, m, a);
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
        f(0, -1, m, a);
        // for(auto i: st){
        //     for(auto j: i) cout<<j<<' ';
        //     cout<<'\n';
        // }
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
        int ind = 0;
        // for(auto i: res){
        //     cout<<ind++<<'-';
        //     for(auto j: i) cout<<j<<' ';
        //     cout<<'\n';
        // }
    }

    int f(int i, int prev, int n, vector<vector<int>> &dp){

        if(i == n) return 1;
        int ans = 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        if(prev == -1){
            for(int k=0; k<res.size(); k++){
                ans = (ans + f(i+1, k, n, dp)) % 1000000007;
            }
        }else{
            for(int k=0; k<res[prev].size(); k++){
                ans = (ans + f(i+1, res[prev][k], n, dp)) % (1000000007);
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