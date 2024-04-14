class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        
        vector<pair<int,int>> adj[n];
        for(auto i: edges){
            adj[i[0]].push_back({ i[1], i[2] });
            adj[i[1]].push_back({ i[0], i[2] });
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        pq.push({ 0, 0 });
        vector<int> dist(n, 1e9);
        dist[0] = 0;
        
        while(!pq.empty()){
            
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            
            if(dis > dist[node]) continue;
            
            for(auto i: adj[node]){
                
                if(dist[i.first] > dis + i.second and disappear[i.first] > dis + i.second){
                    
                    dist[i.first] = dis + i.second;
                    pq.push({ dist[i.first], i.first });
                }
            }
        }
        
        for(auto &i: dist){
            if(i == 1e9) i = -1;
        }
        return dist;
    }
};