class Solution {
    const int mod = 1e9+7;
    int row[3] = {-1, 0, -1};
    int col[3] = {0, -1, -1};
    vector<vector<int>> dp;
public:

    int f(int i, int j, vector<string> &board, vector<vector<int>> &cost){

        if(i == 0 and j == 0){
            return 1;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        for(int k=0; k<3; k++){

            int newx = i + row[k];
            int newy = j + col[k];
            if(newx >= 0 and newy >= 0 and board[newx][newy] != 'X'){
                int val = board[newx][newy] - '0';
                if(cost[i][j] == cost[newx][newy] + val){
                    ans = (ans + f(newx, newy, board, cost)) % mod;
                }
            }
        }
        return dp[i][j] = ans;
    }

    int minCost(int i, int j, vector<string> &board, vector<vector<int>> &costDp){

        if (i == 0 && j == 0) return costDp[0][0] = 0;

        int ans = -1e9;
        if(costDp[i][j] != -1) return costDp[i][j];

        for(int k=0; k<3; k++){

            int newx = i + row[k];
            int newy = j + col[k];
            if(newx >= 0 and newy >= 0 and board[newx][newy] != 'X'){
                int val = board[newx][newy] - '0';
                int x = minCost(newx, newy, board, costDp);
                if(x != -1e9) ans = max(ans, val + x);
            }
        }
        return costDp[i][j] = ans;
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        
        int n = board.size();
        board[0][0] = '0';
        board[n-1][n-1] = '0';
        vector<vector<int>> costDp(n, vector<int>(n, -1));
        int cost = minCost(n-1, n-1, board, costDp);
        if(cost == -1e9) return {0, 0};

        dp.assign(n, vector<int>(n, -1));
        int ways = f(n-1, n-1, board, costDp);
        return { cost, ways };
    }
};

// E12
// 1X1
// 21S
