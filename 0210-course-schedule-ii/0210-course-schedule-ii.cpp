class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[n];
        vector<int> inD(n, 0);
        for(auto i: prerequisites){
            
            adj[i[0]].push_back(i[1]);
            inD[i[1]]++;
        }
        
        queue<int> q;
        vector<int> vis(n, 0);
        vector<int> ans;
        
        for(int i=0; i<n; i++){
            if(inD[i] == 0){
                q.push(i);
                ans.push_back(i);
                vis[i] = 1;
            }
        }
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            for(auto i: adj[node]){
                
                inD[i]--;
                if(inD[i] == 0){
                    q.push(i);
                    ans.push_back(i);
                }
            }
        }
        if(ans.size() != n) return {};
        reverse(ans.begin(), ans.end());
        return ans;
    }
};