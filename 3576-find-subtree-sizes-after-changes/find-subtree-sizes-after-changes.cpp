class Solution {
    vector<int> ans;
public:

    int dfs(int src, vector<int> adj[]){
        int sum = 0;
        for(auto &ch: adj[src]){
            sum += dfs(ch, adj);
        }
        return ans[src] = sum + 1;
    }

    void f(int src, vector<int> adj[], string &s, map<char,int> &mp, vector<int> &a){

        int prev = -1;
        if(mp.count(s[src])){
            prev = mp[s[src]];
        }
        a[src] = prev;
        mp[s[src]] = src;
        for(auto &i: adj[src]){
            f(i, adj, s, mp, a);
        }
        if(prev == -1) mp.erase(s[src]);
        else mp[s[src]] = prev;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        
        int n = parent.size();

        vector<int> adjOrg[n];
        for(int i=0; i<n; i++){
            if(parent[i] == -1) continue;
            adjOrg[parent[i]].push_back(i);
        }

        vector<int> colors(n);
        map<char, int> mp1;
        f(0, adjOrg, s, mp1, colors);

        for(int i=1; i<n; i++){
            if(colors[i] != -1){
                parent[i] = colors[i];
            }
        }

        vector<int> adj[n];
        for(int i=0; i<n; i++){
            if(parent[i] == -1) continue;
            adj[parent[i]].push_back(i);
        }
        ans.assign(n, 0);
        dfs(0, adj);
        return ans;
    }
};