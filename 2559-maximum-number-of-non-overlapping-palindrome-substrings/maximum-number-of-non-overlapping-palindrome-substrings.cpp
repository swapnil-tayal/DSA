class Solution {
    vector<vector<int>> a;
    vector<int> dp;
    int n, k;
    int isPali(string &str){
        int n = str.size();
        for(int i=0; i<n/2; i++){
            if(str[i] != str[n-i-1]) return 0;
        }
        return 1;
    }
public:

    int f(int i){

        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int cnt = 0;
        if(a[i][0] == 1) cnt = 1 + f(i+k);
        if(a[i][1] == 1) cnt = max(cnt, 1 + f(i+k+1));
        cnt = max(cnt, f(i+1));
        return dp[i] = cnt;
    }

    int maxPalindromes(string s, int k) {
        
        this->n = s.size();
        this->k = k;
        dp.assign(n, -1);
        a.assign(n, vector<int>(2));
        for(int i=0; i<=n; i++){

            string subStr = s.substr(i, k);
            if(subStr.size() == k && isPali(subStr)) a[i][0] = 1;
            subStr = s.substr(i, k+1);
            if(subStr.size() == k+1 && isPali(subStr)) a[i][1] = 1;
        }
        return f(0);
    }
};