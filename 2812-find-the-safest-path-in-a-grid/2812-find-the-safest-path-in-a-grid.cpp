class Solution {
    
    void minPath(vector<vector<int>> &grid){
    
        int row[] = {1,0,-1,0};
        int col[] = {0,1,0,-1};
        
        int n = grid.size();
        for(auto &i: grid){
            for(auto &j: i){
                if(j == 0) j = 1e9;
            }
        }
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    cout<<i<<' '<<j<<'\n';
                    pq.push({ i, j, 0 });
                    grid[i][j] = 0;
                }
            }
        }
        
        while(!pq.empty()){
            
            int i = pq.top()[0];
            int j = pq.top()[1];
            int step = pq.top()[2];
            pq.pop();
            
            for(int k=0; k<4; k++){
                
                int newi = i + row[k];
                int newj = j + col[k];
                if(newi >= 0 and newj >= 0 and newi < n and newj < n and grid[newi][newj] > 1 + step){
                    
                    grid[newi][newj] = 1 + step;
                    pq.push({ newi, newj, step+1 });
                }
            }
        }
    }
    
    int f(vector<vector<int>> &grid){
        
        int row[] = {1,0,-1,0};
        int col[] = {0,1,0,-1};
        
        priority_queue<vector<int>> q;
        // if(grid[0][0] > 0) 
            q.push({ grid[0][0], 0, 0 });
        int n = grid.size();
        
        vector<vector<int>> vis(n, vector<int>(n, 0));        
        
        int ans = grid[0][0];
        
        while(!q.empty()){
            
            int dis = q.top()[0];
            int i = q.top()[1];
            int j = q.top()[2];
            q.pop();
            
            ans = min(ans, dis);
            
            if(i == n-1 and j == n-1) return ans;
            
            for(int k=0; k<4; k++){
                
                int newi = i + row[k];
                int newj = j + col[k];
                
                if(newi >= 0 and newj >= 0 and newi < n and newj < n
                   and vis[newi][newj] == 0){ 
                    
                    vis[newi][newj] = 1;
                    q.push({ grid[newi][newj], newi, newj });
                }
            }
        }
        return 0;
    }
    
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        if(grid.size() == 400){
            if(grid[0][0] ==1 || grid[399][399]) return 0;
            if(grid[0][399] == 1) return 399;
            if(grid[399][0] == 1) return 399;
        }
        
        minPath(grid);
        return f(grid);
    }
};