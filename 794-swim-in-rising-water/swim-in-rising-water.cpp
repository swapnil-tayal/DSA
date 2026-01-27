class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({ grid[0][0], 0, 0 });
        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        dis[0][0] = grid[0][0];

        int row[] = {-1,0,1,0};
        int col[] = {0,-1,0,1};

        while(!pq.empty()){
        
            int maxi = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];
            pq.pop();

            for(int k=0; k<4; k++){

                int newi = i + row[k];
                int newj = j + col[k];

                if(newi >= 0 and newj >= 0 and newi < n and newj < n){

                    int val = max(maxi, grid[newi][newj]);
                    if(dis[newi][newj] > val){
                        dis[newi][newj] = val;
                        pq.push({ dis[newi][newj], newi, newj });
                    }
                }
            }
        }
        return dis[n-1][n-1];
    }
};