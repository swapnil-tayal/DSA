class Solution {
    vector<int> pre;
    vector<vector<int>> dp;
public:

    int f(int i, int j, vector<int> &stoneValue){

        if(j-i+1 == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        for(int k=i; k<j; k++){

            int sum1 = pre[k] - (i-1 >= 0 ? pre[i-1] : 0);
            int sum2 = pre[j] - pre[k];

            int val = 0;
            if(sum1 < sum2){
                val = sum1 + f(i, k, stoneValue);
            }else if(sum2 < sum1){
                val = sum2 + f(k+1, j, stoneValue);
            }else{
                val = sum2 + f(k+1, j, stoneValue);
                val = max(val, sum1 + f(i, k, stoneValue));
            }
            ans = max(ans, val);
        }
        return dp[i][j] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        
        int n = stoneValue.size();
        pre.assign(n, 0);
        dp.assign(n, vector<int>(n, -1));
        pre[0] = stoneValue[0];
        for(int i=1; i<n; i++){
            pre[i] = pre[i-1] + stoneValue[i];
        }
        return f(0, n-1, stoneValue);
    }
};