//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
	public:
	void findTopo(int src, vector<int> &vis, vector<int> adj[], vector<int> &topo){
	    
	    vis[src] = 1;
	    for(auto i: adj[src]){
	        
	        if(vis[i]) continue;
	        findTopo(i, vis, adj, topo);
	    }
	    topo.push_back(src);
	}
	
    void findSCC(int src, vector<int> &vis, vector<int> adj[], vector<int> &scc){
        
        scc.push_back(src);
        vis[src] = 1;
        for(auto i: adj[src]){
            if(!vis[i]){
                findSCC(i, vis, adj, scc);
            }
        }
    }
	
    vector<vector<int>> tarjans(int V, vector<int> adj[]){
        //code here
        vector<int> topo, vis(V, 0);
        
        for(int i=0; i<V; i++){
            if(vis[i]) continue;
            findTopo(i, vis, adj, topo);
        }
        reverse(topo.begin(), topo.end());
        // for(auto i: topo) cout<<i<<' ';
        // cout<<'\n';
        
        vector<int> newGraph[V];
        for(int i=0; i<V; i++){
            vis[i] = 0;
            for(auto j: adj[i]){
                newGraph[j].push_back(i);
            }
        }
        int cnt = 0;
        vector<vector<int>> ans;
        
        for(auto &i: topo){
            if(vis[i]) continue;
            vector<int> scc;
            findSCC(i, vis, newGraph, scc);
            sort(scc.begin(), scc.end());
            ans.push_back(scc);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}


// } Driver Code Ends