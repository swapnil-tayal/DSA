class Solution{
    map<pair<int,int>, int> mp;
    int k;
public:
    
    int f(int i, vector<int> &arr, int cnt, vector<vector<int>> &dp){
        
        if(i == arr.size()){
            return cnt * mp[{ i-cnt, i-1 }];
        }
        if(dp[i][cnt] != -1) return dp[i][cnt];
        
        int pick = -1e9;
        if(cnt+1 <= k){
            pick = f(i+1, arr, cnt+1, dp);
        }
        int val = cnt * mp[{ i-(cnt) , i-1 }];
        int npick = val + f(i+1, arr, 1, dp);
        return dp[i][cnt] = max(pick, npick);
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k){
        
        this->k = k;
        int n = arr.size();
        for(int i=0; i<n; i++){
            int maxi = 0;
            for(int j=i; j<n; j++){
                maxi = max(maxi, arr[j]);
                mp[{ i, j }] = maxi;
            }
        }
        // for(auto i: mp){
        //     cout<<i.first.first<<' '<<i.first.second<<'-'<<i.second<<'\n';
        // }
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return f(0, arr, 0, dp);
    }
};