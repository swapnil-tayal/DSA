class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int n = grid.size();
        pq.push({grid[0][0], {0, 0}});
        int rowD[] = {1, 0, -1, 0};
        int colD[] = {0, -1, 0, 1};
        int ans = grid[0][0];
        vector<vector<int>> vis(n, vector<int>(n, 0));
        
        while(!pq.empty()){
            
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            ans = max(ans, pq.top().first);
            pq.pop();vis[row][col] = 1;
            
            if(row == n-1 and col == n-1){
                return ans;
            }
            
            for(int i=0; i<4; i++){
                
                int newR = row + rowD[i];
                int newC = col + colD[i];
                
                if(newR > -1 and newC > -1 and newR < n and newC < n and !vis[newR][newC]){
                    
                    pq.push({grid[newR][newC], {newR, newC}});
                }
            }
        }
        return -1;
    }
};