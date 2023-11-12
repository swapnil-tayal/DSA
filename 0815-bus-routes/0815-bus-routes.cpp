class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        
        if(source == target) return 0;
        unordered_map<int, vector<int>> mp;
        set<int> st;
        
        for(int i=0; i<routes.size(); i++){
            for(int j=0; j<routes[i].size(); j++){
                mp[routes[i][j]].push_back(i);
                if(routes[i][j] == target) st.insert(i);
            }
        }
        
        int n = routes.size();
        vector<int> adj[n];
        for(auto i: mp){
            vector<int> temp = i.second;
            int m = temp.size();
            for(int j=0; j<m; j++){
                for(int k=j+1; k<m; k++){
                    adj[temp[j]].push_back(temp[k]);
                    adj[temp[k]].push_back(temp[j]);
                }
            }
        }
        
        queue<pair<int,int>> q;
        vector<int> vis(n, 0);
        for(auto i: mp[source]){
            q.push({ i,1 });
            vis[i] = 1;
        }
        
        while(!q.empty()){
            
            int node = q.front().first;
            int dis = q.front().second;
            q.pop();
            if(st.count(node)) return dis;
            
            for(auto i: adj[node]){
                
                if(vis[i]) continue;
                vis[i] = 1;
                q.push({ i, dis+1 });
            }
        }
        return -1;
    }
};