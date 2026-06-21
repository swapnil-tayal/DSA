class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        int row[] = {1,-1,0,0};
        int col[] = {0,0,1,-1};

        priority_queue<vector<int>, vector<vector<int>>, greater<>> q;
        q.push({ 0, 0, 0 });
        vector<vector<int>> vis(n, vector<int>(m, 1e9));
        vis[0][0] = 0;

        while(!q.empty()){

            int x = q.top()[1];
            int y = q.top()[2];
            int dis = q.top()[0];
            q.pop();
            if(x == n-1 and y == m-1) return dis;

            for(int k=0; k<4; k++){

                int newx = x + row[k];
                int newy = y + col[k];

                if(newx >= 0 and newy >= 0 and newx < n and newy < m){
                    int val = max(dis, abs(grid[x][y] - grid[newx][newy]));
                    if(vis[newx][newy] > val){
                        vis[newx][newy] = val;
                        q.push({ val, newx, newy });
                    }
                }
            }
        }
        return -1;
    }
};