class Solution {
public:
    void solve(int n,vector<int> &vis, vector<vector<long long>> &vec,long long sum,vector<long long> & dis) {
        for(int i=0;i<26;i++){
            if(i==n || vis[i]==1) continue;
            if(vec[n][i]!=-1){
                if(sum+vec[n][i]<dis[i]){
                    vis[i]=1;
                    dis[i] = sum+vec[n][i];
                    solve(i,vis,vec,dis[i],dis);
                    vis[i]=0;
                }
            }
        }
        return;
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> vec(26,vector<long long>(26,1e18));
        vector<vector<long long>> adj;
        for(int i=0;i<original.size();i++){
            int a = original[i]-'a';
            int b = changed[i]-'a';
            vec[a][b] = min(vec[a][b], (long long)cost[i]);
        }
        for(int i=0;i<26;i++){
            vector<int> vis(26,0);
            vis[i]=1;
            vector<long long> dis(26,1e18);
            solve(i,vis,vec,0,dis);
            adj.push_back(dis);
        }
        long long ans = 0;
        for(int i=0;i<source.size();i++){
            int a = source[i]-'a';
            int b = target[i]-'a';
            if(a==b) continue;
            if(adj[a][b]>=1e18) return -1;
            ans +=adj[a][b];
        }
        return ans;
    }
};