class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int>>> adj(n, vector<pair<int,int>>());
        for(auto &i: edges){
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], 2*i[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({ 0, 0 });
        vector<int> vis(n, 0);
        vector<int> dis(n, 1e9);
        dis[0] = 0;

        while(!pq.empty()){

            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto &i: adj[node]){

                if(dis[i.first] > weight + i.second){
                    dis[i.first] = weight + i.second;
                    pq.push({ dis[i.first], i.first });
                }
            }
        }
        return dis[n-1] == 1e9 ? -1 : dis[n-1];
    }
};