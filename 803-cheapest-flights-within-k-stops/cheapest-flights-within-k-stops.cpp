class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>> adj[n];
        for(auto &i: flights){
            adj[i[0]].push_back({ i[1], i[2] });
        }

        vector<int> dis(n, 1e9);
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({ 0, src, 0 });
        dis[src] = 0;

        while(!pq.empty()){

            int stops = pq.top()[0];
            int node = pq.top()[1];
            int cost = pq.top()[2];
            pq.pop();
            if(stops > k) continue;

            for(auto &i: adj[node]){
                
                if(dis[i.first] > i.second + cost){
                    dis[i.first] = i.second + cost;
                    pq.push({ stops+1, i.first, dis[i.first] });
                }
            }
        }
        return dis[dst] == 1e9 ? -1 : dis[dst];
    }
};