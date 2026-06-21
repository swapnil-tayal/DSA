class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>> adj[n];
        for(auto i: flights){
            
            int v = i[0];
            int u = i[1];
            int dis = i[2];
            adj[v].push_back({ u, dis });
        }
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({ 0, src, k+1 });
        
        vector<vector<int>> dis(n, vector<int>(k+1, 1e9));
        dis[src][k] = 0;
        
        while(!pq.empty()){
            
            int dist = pq.top()[0];
            int node = pq.top()[1];
            int leftK = pq.top()[2];
            pq.pop();
            
            for(auto i: adj[node]){
                
                if(leftK-1 < 0) continue; 
                if(dis[i.first][leftK-1] > i.second + dist){
                    dis[i.first][leftK-1] = i.second + dist;
                    pq.push({ dis[i.first][leftK-1], i.first, leftK-1 });
                }
            }
        }
        int ans = 1e9;
        for(int i=0; i<=k; i++){
            ans = min(ans, dis[dst][i]);
        }
        return ans == int(1e9) ? -1 : ans;
    }
};