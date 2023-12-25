class Solution {
public:
    
    bool f(int src, vector<int> &vis, vector<int> &dfsVis, vector<int> adj[]){
        
        vis[src] = 1;
        dfsVis[src] = 1;
        for(auto i: adj[src]){
            
            if(vis[i]){
                
                if(dfsVis[i]) return true;
                else continue;
                
            }else if(f(i, vis, dfsVis, adj)) return true;
        }
        dfsVis[src] = 0;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& a) {
        
        vector<int> adj[n];
        for(auto i: a){
            adj[i[0]].push_back(i[1]);
        }
        vector<int> vis(n, 0);
        vector<int> dfsVis(n, 0);
        for(int i=0; i<n; i++){
            
            if(vis[i]) continue;
            if(f(i, vis, dfsVis, adj)) return !true;
        }
        return !false;
    }
};