class Solution {
public:
    
    void dfs(int src, vector<int> adj[], vector<int> &vis, vector<int> &temp){
        
        vis[src] = 1;
        temp.push_back(src);
        for(auto i: adj[src]){
            if(vis[i]){
                temp.push_back(i);
                continue;
            }
            dfs(i, adj, vis, temp);
        }
    }
    
    vector<int> countVisitedNodes(vector<int>& edges) {
        
        int n = edges.size();
        vector<int> adj[n];
        for(int i=0; i<n; i++){
            adj[i].push_back(edges[i]);
        }
        
        vector<int> vis(n, 0);
        vector<int> ans(n, 0);
        
        for(int i=0; i<n; i++){
            
            if(vis[i]) continue;
            vector<int> temp;
            dfs(i, adj, vis, temp);
            
            // for(auto &it: temp) cout<<it<<' ';
            // cout<<'\n';
            
            if(temp.back() == temp[0]){
                for(auto &it: temp){
                    ans[it] = temp.size()-1;
                }
            
            }else{
                
                if(ans[temp.back()]){
                    
                    int k = ans[temp.back()];
                    int it = 0;
                    while(it < temp.size()){
                        if(temp[it] == temp.back()) break;
                        it++;
                    }
                    it--;
                    while(it >= 0){
                        ans[temp[it]] = ++k;
                        it--;
                    }
                
                }else{
                    
                    int it = 0;
                    while(it < temp.size()){
                        if(temp[it] == temp.back()) break;
                        it++;
                    }
                    int k = temp.size()-it-1;
                    for(int j=it; j<temp.size(); j++){
                        ans[temp[j]] = k; 
                    }
                    // cout<<it<<' ';
                    // cout<<temp[it]<<' ';
                    // cout<<k<<' ';
                    it--;
                    while(it >= 0){
                        ans[temp[it]] = ++k;
                        it--;
                    }
                }
            }
        }
        return ans;
    }
};