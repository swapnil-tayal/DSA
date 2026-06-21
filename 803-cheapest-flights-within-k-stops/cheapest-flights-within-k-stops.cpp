class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>> adj[n];
        for(auto &i: flights){
            adj[i[0]].push_back({ i[1], i[2] });
        }

        vector<vector<int>> dis(n, vector<int>(k+1, 1e9));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({ 0, src, k+1 });
        dis[src][k] = 0;

        while(!pq.empty()){

            int dist = pq.top()[0];
            int node = pq.top()[1];
            int stops = pq.top()[2];
            pq.pop();

            for(auto &i: adj[node]){
                
                if(stops-1 < 0) continue;
                if(dis[i.first][stops-1] > i.second + dist){
                    dis[i.first][stops-1] = i.second + dist;
                    pq.push({ dis[i.first][stops-1], i.first, stops-1 });
                }
            }
        }
        int ans = 1e9;
        for(auto &i: dis[dst]){
            ans = min(ans, i);
        }
        return ans == 1e9 ? -1 : ans;
    }
};