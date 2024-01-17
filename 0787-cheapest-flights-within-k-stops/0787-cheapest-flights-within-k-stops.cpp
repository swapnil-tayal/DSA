class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({ 0, src, k+1 });
        
        vector<pair<int,int>> adj[n];
        for(auto i: flights){
            adj[i[0]].push_back({ i[1], i[2] });
        }
        vector<vector<int>> dis(n, vector<int>(k+2, 1e9));
        
        dis[src][k+1] = 0;
        
        while(!pq.empty()){
            
            int node = pq.top()[1];
            int dist = pq.top()[0];
            int leftK = pq.top()[2];
            pq.pop();
            // cout<<node<<' '<<leftK<<'\n';
            
            if(leftK >= 0 and node == dst) return dist;
            if(leftK < 0) continue;
            
            for(auto i: adj[node]){
                
                if(dis[i.first][leftK] > i.second + dist){
                // if(vis[i.first][leftK-1]) continue;
                // vis[i.first][leftK-1] = 1;
                    dis[i.first][leftK] = i.second + dist;
                    pq.push({ dis[i.first][leftK], i.first, leftK-1 });
                }
            }
        }
        return -1;
    }
};