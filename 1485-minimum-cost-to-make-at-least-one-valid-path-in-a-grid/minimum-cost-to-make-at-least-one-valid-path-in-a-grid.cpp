class Solution {
public:
    
    void makeGraph(vector<vector<int>> &grid, vector<pair<int,int>> adj[]){
        
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){        
                
                // cout<<i*m + j<<' ';
                
                if(grid[i][j] == 1){
                    if(i+1 < n) adj[i*m + j].push_back( {(i+1)*m + j, 1} );
                    if(i-1 >= 0) adj[i*m + j].push_back( {(i-1)*m + j, 1} );
                    if(j+1 < m) adj[i*m + j].push_back( {i*m + (j+1), 0} );
                    if(j-1 >= 0) adj[i*m + j].push_back( {i*m + (j-1), 1} );
                
                }else if(grid[i][j] == 2){
                    if(i+1 < n) adj[i*m + j].push_back( {(i+1)*m + j, 1} );
                    if(i-1 >= 0) adj[i*m + j].push_back( {(i-1)*m + j, 1} );
                    if(j+1 < m) adj[i*m + j].push_back( {i*m + (j+1), 1} );
                    if(j-1 >= 0) adj[i*m + j].push_back( {i*m + (j-1), 0} );
                    
                }else if(grid[i][j] == 3){
                    if(i+1 < n) adj[i*m + j].push_back( {(i+1)*m + j, 0} );
                    if(i-1 >= 0) adj[i*m + j].push_back( {(i-1)*m + j, 1} );
                    if(j+1 < m) adj[i*m + j].push_back( {i*m + (j+1), 1} );
                    if(j-1 >= 0) adj[i*m + j].push_back( {i*m + (j-1), 1} );
                    
                }else{
                    if(i+1 < n) adj[i*m + j].push_back( {(i+1)*m + j, 1} );
                    if(i-1 >= 0) adj[i*m + j].push_back( {(i-1)*m + j, 0} );
                    if(j+1 < m) adj[i*m + j].push_back( {i*m + (j+1), 1} );
                    if(j-1 >= 0) adj[i*m + j].push_back( {i*m + (j-1), 1} );
                }
            }
        }
    }
    
    int dijkstra(vector<pair<int,int>> adj[], int n){
    
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; 
        pq.push({0, 0});
        vector<int> dis(n, 1e9);
        
        while(!pq.empty()){
            
            int nodeDis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto i: adj[node]){
                
                int childDis = i.second;
                int child = i.first;
                
                if(nodeDis + childDis < dis[child]){
                    dis[child] = nodeDis + childDis;
                    pq.push({nodeDis + childDis, child});
                }
            }
        }
        return dis[n-1];
    }
    
    int minCost(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        if(n*m == 1) return 0;
        
        vector<pair<int,int>> adj[n*m];
        makeGraph(grid, adj);
        
        // for(int i=0; i<n*m; i++){
        //     cout<<i<<"->";
        //     for(auto j: adj[i]){
        //         cout<<j.first<<' '<<j.second<<" , ";
        //     }cout<<'\n';
        // }
        
        return dijkstra(adj, n*m);
    }
};