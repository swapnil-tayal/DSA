class Solution {
    int cnt;
public:
    
    int f(int src, vector<int> &vis, vector<int> adj[]){
        
        vis[src] = 1;
        set<int> st;
        int size = 0;
        
        for(auto i: adj[src]){
            
            if(vis[i]) continue;
            int child = f(i, vis, adj);
            st.insert(child);
            size += child;
        }
        
        if(st.size() <= 1){
            // cout<<src<<' ';
            cnt++;
        }
        return size+1;
    
    }
    
    int countGoodNodes(vector<vector<int>>& edges) {
        
        int n = edges.size();
        vector<int> adj[n+1];
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        this->cnt = 0;
        vector<int> vis(n+1, 0);
        f(0, vis, adj);
        return cnt;
    }
};