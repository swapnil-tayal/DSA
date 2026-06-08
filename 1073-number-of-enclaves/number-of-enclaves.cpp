class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {

        int n = board.size();
        int m = board[0].size();

        queue<vector<int>> q;
        for(int i=0; i<n; i++){
            if(board[i][0] == 1) q.push({ i, 0 });
            if(board[i][m-1] == 1) q.push({ i, m-1 });
        }
        for(int j=0; j<m; j++){
            if(board[0][j] == 1) q.push({ 0, j });
            if(board[n-1][j] == 1) q.push({ n-1, j });
        }

        int row[] = {-1,1,0,0};
        int col[] = {0,0,-1,1};

        while(!q.empty()){

            int x = q.front()[0];
            int y = q.front()[1];
            board[x][y] = 0;
            q.pop();

            for(int k=0; k<4; k++){
                int newx = x + row[k];
                int newy = y + col[k];

                if(newx >= 0 and newy >= 0 and newx < n and newy < m){
                    if(board[newx][newy] == 1){
                        board[newx][newy] = 0;
                        q.push({ newx, newy });
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == 0 || j == 0 || i == n-1 || j == m-1) continue;
                if(board[i][j] == 1) ans++;
            }
        }
        return ans;
    }
};