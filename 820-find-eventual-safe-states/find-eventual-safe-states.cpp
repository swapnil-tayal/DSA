class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n =  graph.size();
        vector<int> adj[n];
        vector<int> inD(n, 0);

        for(int i=0; i<n; i++){
            for(auto &j: graph[i]){
                adj[j].push_back(i);
                inD[i]++;
            }
        }
        queue<int> q;
        vector<int> ans;

        for(int i=0; i<n; i++){
            if(inD[i] == 0){
                q.push(i);
                ans.push_back(i);
            }
        }

        while(!q.empty()){

            int node = q.front();
            q.pop();

            for(auto &i: adj[node]){
                inD[i]--;
                if(inD[i] == 0){
                    q.push(i);
                    ans.push_back(i);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};