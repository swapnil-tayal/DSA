class Solution {
public:
    
    bool check(vector<int> adj[], int src, int des, vector<int> &vis){
        
        queue<int> q;
        q.push(src);
         
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            vis[node] = 1;
            if(node == des) return true;
             
            for(auto i: adj[node]){
                if(!vis[i]){
                    q.push(i);
                }
            }
        }
        return false;
    }
     
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<int> adj[n];
        vector<int> vis(n, 0);
         
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return check(adj, source, destination, vis);
    }
};