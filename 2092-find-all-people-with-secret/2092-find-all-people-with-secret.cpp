bool cmp(vector<int> &a1, vector<int> &a2){
    return a1[2] <= a2[2];
}

class Solution{
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        int m = meetings.size();
        // sort(meetings.begin(), meetings.end());
        vector<pair<int,int>> adj[n];
        
        for(int i=0; i<m; i++){    
            int v = meetings[i][0];
            int u = meetings[i][1];
            int x = meetings[i][2];
            adj[v].push_back({ u, x });
            adj[u].push_back({ v, x });
        }
        
        queue<pair<int,int>> q;
        q.push({ 0, 0 });
        q.push({ firstPerson, 0 });
        
        set<int> st;
        set<vector<int>> vis;
        vector<int> dis(n, 1e9);
        
        while(!q.empty()){
            
            int node = q.front().first;
            int time = q.front().second;
            st.insert(node);
            q.pop();
            
            for(auto i: adj[node]){
                
                if(i.second >= time and vis.count({ node, i.first, i.second }) == 0 and
                    vis.count({ i.first, node, i.second }) == 0
                    and dis[i.first] >= i.second){
                    
                    dis[i.first] = i.second;
                    vis.insert({ node, i.first, i.second });
                    vis.insert({ i.first, node, i.second });
                    q.push({ i.first, i.second });
                }
            }
        }
        vector<int> ans (st.begin(), st.end());
        return ans;
    }
};