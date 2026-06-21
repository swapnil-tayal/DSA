class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        int row[] = {1, 1, 0, -1, 0, -1, 1, -1};
        int col[] = {1, 0, 1, 0, -1, -1, -1, 1};

        if(grid[0][0] != 0) return -1;

        queue<vector<int>> q;
        q.push({ 0, 0, 1 });
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vis[0][0] = 1;

        while(!q.empty()){

            int x = q.front()[0];
            int y = q.front()[1];
            int dis = q.front()[2];
            q.pop();
            if(x == n-1 and y == n-1) return dis;

            for(int k=0; k<8; k++){

                int newx = x + row[k];
                int newy = y + col[k];

                if(newx >= 0 and newy >= 0 and newx < n and newy < n and vis[newx][newy] == 0 and grid[newx][newy] == 0){

                    vis[newx][newy] = 1;
                    q.push({ newx, newy, dis+1 });
                }
            }
        }
        return -1;
    }
};