class Solution {
public:
    
    bool f(int src, vector<int> &color, vector<vector<int>> &graph){
        
        queue<pair<int,int>> q;
        q.push({src, -1});
        color[src] = 1;
        
        while(!q.empty()){
            
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
            
            for(auto i: graph[node]){
                
                if(i == par) continue;
                if(color[i] != -1){
                    
                    if(color[i] == color[node]) return false;
                
                }else{
                    color[i] = 1 - color[node];
                    q.push({ i, node });
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> color(n, -1);
        
        for(int i=0; i<n; i++){
            
            if(color[i] == -1){
                if(!f(i, color, graph)) return false;
            }
        }
        return true;
    }
};