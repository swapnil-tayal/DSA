class Solution {
public:
    
    bool f(int src, int par, vector<int> &color, vector<vector<int>> &graph){
        
        if(par == -1) color[src] = 1;
        else color[src] = 1 - color[par];
        
        for(auto i: graph[src]){
            
            if(i == par) continue;
            if(color[i] != -1){
                
                if(color[i] == color[src]) return false;
            
            }else if(!f(i, src, color, graph)) return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> color(n, -1);
        
        for(int i=0; i<n; i++){
            
            if(color[i] == -1){
                if(!f(i, -1, color, graph)) return false;
            }
        }
        return true;
    }
};