class Solution {
public:

    bool f(int src, int prev, vector<int> &color, vector<vector<int>> &graph){

        color[src] = 1-prev;
        for(auto &i: graph[src]){
            if(color[i] != -1){
                if(color[i] != prev) return false;
                continue;
            }
            if(!f(i, 1-prev, color, graph)) return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i=0; i<n; i++){
            if(color[i] != -1) continue;
            if(!f(i, 0, color, graph)) return false;
        }
        return true;
    }
};