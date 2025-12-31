class Solution {
public:

    int bfs(int mid, int row, int col, vector<vector<int>> &cells){

        vector<vector<int>> grid(row, vector<int>(col, 0));
        for(int i=0; i<=mid; i++){
            grid[cells[i][0]-1][cells[i][1]-1] = 1;
        }

        vector<vector<int>> vis(row, vector<int>(col, 0));
        queue<pair<int,int>> q;
        for(int i=0; i<col; i++){
            if(grid[0][i] == 0){
                q.push({ 0, i });
                vis[0][i] = 1;
            }
        }

        int rows[4] = {0,0,-1,1};
        int cols[4] = {-1,1,0,0};

        while(!q.empty()){

            int i = q.front().first;
            int j = q.front().second;
            if(i == row-1) return 1;
            q.pop();

            for(int k=0; k<4; k++){

                int newi = i + rows[k];
                int newj = j + cols[k];
                if(newi >= 0 and newj >= 0 and newi < row and newj < col and vis[newi][newj] == 0 and grid[newi][newj] == 0){
                    vis[newi][newj] = 1;
                    q.push({newi, newj});
                }
            }
        }
        return 0;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        int n = cells.size();
        int s = 0;
        int e = n-1;
        int ans = 0;

        while(s <= e){

            int mid = (s+e)/2;
            if(bfs(mid, row, col, cells)){
                ans = mid;
                s = mid+1;

            }else e = mid-1;
        }
        return ans+1;
    }
};