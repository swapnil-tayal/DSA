class Solution {
    vector<int> dp;
public:

    int f(int src, vector<int> adj[]){

        int ans = 0;
        if(dp[src] != -1) return dp[src];
        for(auto &i: adj[src]){
            ans = max(ans, f(i, adj));
        }
        return dp[src] = ans + 1;
    }

    int maxJumps(vector<int>& arr, int d) {
        
        int n = arr.size();
        vector<int> adj[n];

        for(int i=0; i<n; i++){
            
            for(int k=i+1; k<=min(n-1, i+d); k++){
                if(arr[k] < arr[i]){
                    adj[i].push_back(k);
                } else break;
            }
            for(int k=i-1; k>=max(0, i-d); k--){
                if(arr[k] < arr[i]){
                    adj[i].push_back(k);
                } else break;
            }
        }
        dp.resize(n, -1);
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, f(i, adj));
        }
        return ans;
    }
};