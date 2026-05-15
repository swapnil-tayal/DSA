class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int row[] = {1,-1,0,0};
        int col[] = {0,0,-1,1};

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        int ans = 0;
        while(!q.empty()){

            int y = q.size();
            while(y--){

                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for(int k=0; k<4; k++){

                    int newi = row[k] + x;
                    int newj = col[k] + y;

                    if(newi >= 0 and newj >= 0 and newi < n and newj < m and grid[newi][newj] == 1){
                        grid[newi][newj] = 2;
                        q.push({ newi, newj });
                    }
                }
            }
            ans++;
        }
        for(auto &i: grid){
            for(auto &j: i){
                if(j == 1){
                    return -1;
                }
            }
        }
        return ans == 0 ? 0 :ans-1;
    }
};