class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& edges) {

        vector<int> inD(V, 0);
        vector<int> adj[V];
        for(auto &i: edges){
            adj[i[0]].push_back(i[1]);
            inD[i[1]]++;
        }
        
        queue<int> q;
        vector<int> ans;
        for(int i=0; i<V; i++){
            if(inD[i] == 0){
                q.push(i);
            }
        }
        int cnt = 0;
        while(!q.empty()){
            
            int x = q.front();
            cnt++;
            q.pop();
            ans.push_back(x);
            for(auto &i: adj[x]){
                inD[i]--;
                if(inD[i] == 0){
                    q.push(i);
                }
            }
        }
        return cnt == V;
    }
};