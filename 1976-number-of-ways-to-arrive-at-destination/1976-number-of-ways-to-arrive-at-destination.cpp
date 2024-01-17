class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pair<int,int>> adj[n];
        for(auto i: roads){
            adj[i[0]].push_back({ i[1], i[2] });
            adj[i[1]].push_back({ i[0], i[2] });
        }
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({ 0, 0 });
        
        vector<long long> ways(n, 0);
        vector<long long> dis(n, LONG_MAX);
        dis[0] = 0;
        ways[0] = 1;
        
        while(!pq.empty()){
            
            int node = pq.top().second;
            long long dist = pq.top().first;
            pq.pop();
            
            for(auto i: adj[node]){
                
                if(dis[i.first] > i.second + dist){
                    dis[i.first] = i.second + dist;
                    ways[i.first] = ways[node];
                    pq.push({ dis[i.first], i.first });
                
                }else if(dis[i.first] == i.second + dist){
                    ways[i.first] = (ways[node] + ways[i.first]) % int(1e9+7);
                }
            }
        }
        return ways[n-1] % int(1e9+7);
    }
};