class Solution {
public:

    double bfs(string src, string des, map<string, vector<pair<string, double>>> adj){
        
        queue<pair<string, double>> q;
        q.push({ src, 1.0 });
        set<string> vis;
        vis.insert(src);

        while(!q.empty()){

            string node = q.front().first;
            double sum = q.front().second;
            q.pop();
            if(node == des) return sum;

            for(auto &i: adj[node]){
                if(vis.count(i.first)) continue;
                vis.insert(i.first);
                q.push({ i.first, sum * i.second });
            }
        }
        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        map<string, vector<pair<string, double>>> adj;
        for(int i=0; i<equations.size(); i++){
            adj[equations[i][0]].push_back({ equations[i][1], values[i] });
            adj[equations[i][1]].push_back({ equations[i][0], 1/(double)values[i] });
        }

        vector<double> ans;
        for(auto &i: queries){
            if(adj.count(i[1]) == 0 || adj.count(i[0]) == 0) ans.push_back(-1);
            else ans.push_back(bfs(i[0], i[1], adj));
        }
        return ans;
    }
};