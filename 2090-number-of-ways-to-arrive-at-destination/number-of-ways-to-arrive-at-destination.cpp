class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<pair<int,int>> adj[n];
        for(auto i: roads){
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        vector<long long> ways(n, 0);
        vector<long long> dist(n, LONG_MAX);
        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while(!pq.empty()){

            int node = pq.top().second;
            long long dis = pq.top().first;
            pq.pop();

            for(auto i: adj[node]){

                if(dist[i.first] > dis + i.second){

                    dist[i.first] = dis + i.second;
                    ways[i.first] = ways[node];
                    pq.push({ dist[i.first], i.first });

                }else if(dist[i.first] == dis + i.second){
                    ways[i.first] = (ways[i.first] + ways[node]) % int(1e9+7);
                }
            }
        }
        return ways[n-1] % int(1e9+7);
    }
};