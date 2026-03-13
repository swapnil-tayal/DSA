class Solution {
public:

    void bfs(vector<vector<char>> &grid, int x, int y){

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        q.push({ x, y });
        grid[x][y] = '.';

        int row[] = {-1,1,0,0};
        int col[] = {0,0,-1,1};

        while(!q.empty()){
            
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int k=0; k<4; k++){

                int newx = x + row[k];
                int newy = y + col[k];
                if(newx >= 0 and newy >= 0 and newx < n and newy < m and grid[newx][newy] == 'X'){
                    grid[newx][newy] = '.';
                    q.push({ newx, newy });
                }
            }
        }
    }

    int countBattleships(vector<vector<char>>& board) {
        
        int ans = 0;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){

                if(board[i][j] == 'X'){
                    ans++;
                    bfs(board, i, j);
                }
            }
        }
        return ans;
    }
};