class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();

        queue<vector<int>> q;
        vector<vector<int>> dis(n, vector<int>(m, 1e9));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0) q.push({ i, j });
                if(mat[i][j] == 0) dis[i][j] = 0;
            }
        }

        int row[] = { -1, 1, 0, 0 };
        int col[] = { 0, 0, -1, 1 };

        while(!q.empty()){

            int x = q.front()[0];
            int y = q.front()[1];
            q.pop();

            for(int k=0; k<4; k++){

                int newx = x + row[k];
                int newy = y + col[k];
                
                if(newx >= 0 and newy >= 0 and newx < n and newy < m){
                    if(dis[newx][newy] > dis[x][y] + 1){
                        dis[newx][newy] = dis[x][y] + 1;
                        q.push({ newx, newy });
                    }
                }
            }
        }
        return dis;
    }
};