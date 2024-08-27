class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<pair<int,double>> adj[n];
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        vector<int> vis(n, 0);
        priority_queue<pair<int,double>> pq;
        
        pq.push({ start, 1 });
        vector<double> dis(n, 0);
        dis[start] = 1;
        
        while(!pq.empty()){
            
            int node = pq.top().first;
            double dist = pq.top().second;
            pq.pop();
            
            for(auto &i: adj[node]){
                if(dist * i.second > dis[i.first]){
                    dis[i.first] = dist * i.second;
                    pq.push({ i.first, dis[i.first] });
                }
            }
        }
        return dis[end];
    }
};