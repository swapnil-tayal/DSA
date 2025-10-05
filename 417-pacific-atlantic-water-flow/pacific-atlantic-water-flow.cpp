class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        vector<vector<int>> ans;
        int n = heights.size();
        int m = heights[0].size();
        queue<vector<int>> q;
        vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(2, 0)));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == 0 || j == 0){
                    vis[i][j][1] = 1;
                    q.push({i, j, 1});
                }
                if(i == n-1 || j == m-1){
                    q.push({i, j, 0});
                    vis[i][j][0] = 1;
                }
            }
        }

        int row[4] = {0,0,-1,1};
        int col[4] = {-1,1,0,0};

        while(!q.empty()){

            int x = q.front()[0];
            int y = q.front()[1];
            int o = q.front()[2];
            q.pop();

            for(int k=0; k<4; k++){

                int newx = x + row[k];
                int newy = y + col[k];

                if(newx < 0 || newy < 0 || newx >= n || newy >= m) continue;
                if(heights[x][y] > heights[newx][newy] || vis[newx][newy][o] == 1) continue;
                vis[newx][newy][o] = 1;
                q.push({ newx, newy, o });

            }
        }

        // for(auto i: vis){
        //     for(auto j: i){
        //         cout<<"["<<j[0]<<' '<<j[1]<<"] ,";
        //     }
        //     cout<<'\n';
        // }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j][0] && vis[i][j][1]){
                    ans.push_back({ i, j });
                }
            }
        }
        return ans;
    }
};