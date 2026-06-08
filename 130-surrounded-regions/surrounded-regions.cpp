class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();

        queue<vector<int>> q;
        for(int i=0; i<n; i++){
            if(board[i][0] == 'O') q.push({ i, 0 });
            if(board[i][m-1] == 'O') q.push({ i, m-1 });
        }
        for(int j=0; j<m; j++){
            if(board[0][j] == 'O') q.push({ 0, j });
            if(board[n-1][j] == 'O') q.push({ n-1, j });
        }

        int row[] = {-1,1,0,0};
        int col[] = {0,0,-1,1};

        while(!q.empty()){

            int x = q.front()[0];
            int y = q.front()[1];
            board[x][y] = '.';
            q.pop();

            for(int k=0; k<4; k++){
                int newx = x + row[k];
                int newy = y + col[k];

                if(newx >= 0 and newy >= 0 and newx < n and newy < m){
                    if(board[newx][newy] == 'O'){
                        q.push({ newx, newy });
                    }
                }
            }
        }

        for(auto &i: board){
            for(auto &j: i){
                if(j == '.') j = 'O';
                else j = 'X';
            }
        }
        return;
    }
};