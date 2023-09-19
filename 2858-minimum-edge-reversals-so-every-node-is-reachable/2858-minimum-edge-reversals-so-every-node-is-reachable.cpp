class Solution{
    vector<int> ans;
public:
    
    int bfs(vector<int> adj[], set<int> org[], int n){
        queue<int> q;
        q.push(0);
        int cnt = 0;
        vector<int> vis(n, 0);
        vis[0] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto i: adj[node]){
                
                if(vis[i]) continue;
                vis[i] = 1;
                if(org[node].count(i) == 0) cnt++;
                q.push(i);
            }
        }
        return cnt;
    }
    
    void bfs2(int n, int k, vector<int> adj[], set<int> org[]){
        
        queue<pair<int,int>> q;
        q.push({0, k});
        vector<int> vis(n, 0);
        vis[0] = 1;
        
        while(!q.empty()){
            
            int node = q.front().first;
            int val = q.front().second;
            q.pop();
            
            for(auto i: adj[node]){
                
                if(vis[i]) continue;
                vis[i] = 1;
                if(org[node].count(i)){
                    
                    ans[i] = val+1;
                    q.push({ i, val+1 });
                
                }else{
                    
                    ans[i] = val-1;
                    q.push({ i, val-1 });
                }
            }
        }
    }
    
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        
        ans.resize(n, 0);
        vector<int> adj[n];
        set<int> org[n];
        
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            org[i[0]].insert(i[1]);
        }
        
        int k = bfs(adj, org, n);
        bfs2(n, k, adj, org);
        ans[0] = k;
        return ans;
    }
};