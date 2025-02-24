#define pb push_back

class Solution {
    
    int ans = -1e9;
public:
    
    void dfs(int src, int prev, vector<int> &parent, vector<int> &dis, int len, vector<int> adj[]){
        
        dis[src] = len;
        parent[src] = prev;
        
        for(auto i: adj[src]){
            if(i == prev) continue;
            dfs(i, src, parent, dis, len+1, adj);
        }
        return;
    }
    
    void dfs2(int src, vector<int> adj[], vector<int> &amount, int dis, int prev){
        
        dis += amount[src];
        
        if(adj[src].size() == 1 and src != 0){
            ans = max(ans, dis);
        }
        
        for(auto i: adj[src]){
            if(i == prev) continue;
            dfs2(i, adj, amount, dis, src);
        }
    }   
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        
        int n = amount.size();
        
        vector<int> adj[n];
        for(auto i: edges){
            adj[i[0]].pb(i[1]);
            adj[i[1]].pb(i[0]);
        }
        
        vector<int> parent(n), dis(n);
        
        dfs(0, -1, parent, dis, 0, adj);
        
        
        int curr = bob;
        int bobDis = 0;
        
        while(curr != -1){
            
            if(dis[curr] == bobDis){
                amount[curr] /= 2;
                break;
            
            }else if(dis[curr] > bobDis){
                amount[curr] = 0;
                
            }curr = parent[curr];
            bobDis++;
        }
        
        for(auto i: amount) cout<<i<<" ";
        
        int currDis = 0;
        dfs2(0, adj, amount, currDis, -1);
        
        return ans;
    }
};