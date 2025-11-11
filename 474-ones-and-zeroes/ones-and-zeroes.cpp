class Solution {
    int m;
    int n;
public:

    int f(int i, vector<vector<int>> &arr, int zeros, int one, vector<vector<vector<int>>> &dp){
        if(zeros > m or one > n) return -1e9;
        if(i == arr.size()){
            if(zeros > m or one > n) return -1e9;
            else return 0;
        }
        if(dp[i][zeros][one] != -1) return dp[i][zeros][one];
        int pick = 1 + f(i+1, arr, zeros + arr[i][0], one + arr[i][1], dp);
        int npick = f(i+1, arr, zeros, one, dp);
        return dp[i][zeros][one] = max(pick, npick);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        
        this->m = m;
        this->n = n;
        vector<vector<int>> arr;
        for(auto &i: strs){
            int cnt = 0;
            for(auto &j: i) if(j == '0') cnt++;
            arr.push_back({ cnt, (int)i.size()-cnt });
        }
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return f(0, arr, 0, 0, dp);
    }
};