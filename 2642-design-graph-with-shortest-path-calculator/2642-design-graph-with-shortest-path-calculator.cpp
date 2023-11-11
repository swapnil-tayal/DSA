class Graph{
    
    vector<pair<int,int>> adj[101];
public:
    Graph(int n, vector<vector<int>>& edges) {
        
        for(auto i: edges){
            adj[i[0]].push_back({ i[1], i[2] });
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({ edge[1], edge[2] });
    }
    
    int shortestPath(int node1, int node2){
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({ 0, node1 });
        vector<int> dis(101, 1e9);
        dis[node1] = 0;
        
        while(!pq.empty()){
            
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            
            for(auto i: adj[node]){
                
                if(dis[i.first] > i.second + dist){
                    dis[i.first] = i.second + dist;
                    pq.push({ dis[i.first], i.first });
                }
            }
        }
        return dis[node2] == 1e9 ? -1 : dis[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */