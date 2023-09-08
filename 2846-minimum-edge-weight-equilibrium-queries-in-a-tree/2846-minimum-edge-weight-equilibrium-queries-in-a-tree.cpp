class Solution{
    
    vector<int> parent;
    vector<int> vis;
    vector<vector<int>> table;
    vector<int> level;
    const int MAX = 17;
    vector<vector<int>> freq;
    
public:
    
    void dfsPar(int src, int par, vector<pair<int,int>> adj[], int lvl, vector<int> &freqTemp){
        
        parent[src] = par;
        vis[src] = 1;
        level[src] = lvl;
        freq[src] = freqTemp;
        for(auto i: adj[src]){
            if(vis[i.first]) continue;
            freqTemp[i.second]++;
            dfsPar(i.first, src, adj, lvl+1, freqTemp);
            freqTemp[i.second]--;
        }
    }
    
    void makeTable(int n){
        
        for(int i=0; i<n; i++){
            if(parent[i] == -1) table[i][0] = 0;
            else table[i][0] = parent[i];
        }
        for(int j=1; j<MAX; j++){
            for(int i=0; i<n; i++){
                table[i][j] = table[table[i][j-1]][j-1];
            }
        }
    }
    
    int lca(int a, int b){
        
        if(level[a] < level[b]) swap(a, b);
        // cout<<a<<' ';
        // cout<<level[a];
        int diff = level[a] - level[b];
        // int diff = 0;
        // cout<<diff<<'\n';
        // return 0;
        
        for(int i=0; i<MAX; i++){
            
            int mask = (1<<i);
            if((mask & diff) > 0){
                a = table[a][i];
            }
        }
        
        if(a == b) return a;
        
        for(int i=MAX-1; i>=0; i--){
            
            int newa = table[a][i];
            int newb = table[b][i];
            
            if(newa != newb){
                a = newa;
                b = newb;
            }
        }
        return parent[a];
        // cout<<a<<' '<<b<<'\n';
    }
    
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        
        table.resize(n, vector<int>(17, -1));
        parent.resize(n, -1);
        vis.resize(n, 0);
        level.resize(n, 0);
        freq.resize(n);

        // if(edges.size() == 0){
        //     vector<int> ans(queries.size(), 0);
        //     return ans;
        // }
        
        vector<pair<int,int>> adj[n];
        for(auto i: edges){
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        
        vector<int> freqTemp(27, 0);
        dfsPar(0, -1, adj, 0, freqTemp);
     
        // for(auto i: level) cout<<i<<' ';
        // cout<<'\n';
        // return {};
        // for(int i=0; i<n; i++){
        //     for(int j=1; j<27; j++){
        //         cout<<freq[i][j]<<' ';
        //     }cout<<'\n';
        // }        
        makeTable(n);
        // for(int i=0; i<n; i++){
        //     for(int j=1; j<3; j++){
        //         cout<<table[i][j]<<' ';
        //     }cout<<'\n';
        // }

        // int LCA = lca(5, 4);
        // return {};
        
        

        
        vector<int> ans;
        for(auto it: queries){

            vector<int> newFreq(27, -1);
            int a = it[0];
            int b = it[1];
            int sum = 0;
            int maxFreq = 0;
            int LCA = lca(a, b);
            // cout<<LCA<<' ';
            
            for(int i=0; i<27; i++){

                newFreq[i] = freq[a][i] + freq[b][i] - 2*freq[LCA][i];
                sum += newFreq[i];
                maxFreq = max(maxFreq, newFreq[i]);
            }
            sum -= maxFreq;
            ans.push_back(sum);
        // for(auto i: newFreq) cout<<i<<" ";
        // cout<<'\n';
        }
        
        return ans;
    }
};