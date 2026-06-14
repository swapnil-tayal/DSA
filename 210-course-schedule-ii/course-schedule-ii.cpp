class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {

        vector<int> inD(V, 0);
        vector<int> adj[V];
        for(auto &i: edges){
            adj[i[1]].push_back(i[0]);
            inD[i[0]]++;
        }
        
        queue<int> q;
        vector<int> ans;
        for(int i=0; i<V; i++){
            if(inD[i] == 0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            
            int x = q.front();
            topo.push_back(x);
            q.pop();
            ans.push_back(x);
            for(auto &i: adj[x]){
                inD[i]--;
                if(inD[i] == 0){
                    q.push(i);
                }
            }
        }
        if(topo.size() == V) return topo;
        return {};
    }
};