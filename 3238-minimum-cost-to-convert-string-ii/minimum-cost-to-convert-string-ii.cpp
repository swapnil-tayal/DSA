class Solution {
    map<string,int> mp;
    vector<vector<long long>> dis;
    set<int> st;
    long long MAXI = 1e15;
public:

    int check(string str1, string str2){
        if(mp.count(str1) and mp.count(str2)){
            if(dis[mp[str1]][mp[str2]] == MAXI) return -1;
            else return dis[mp[str1]][mp[str2]];
        }
        return -1;
    }

    long long f(int i, string &source, string &target, int n, vector<long long> &dp){

        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];

        long long ans = MAXI;
        if(source[i] == target[i]) ans = min(ans, f(i+1, source, target, n, dp));
        for(auto &k: st){
            if(i+k > n) continue;
            string str1 = source.substr(i, k);
            string str2 = target.substr(i, k);
            if(mp.count(str1) and mp.count(str2) and check(str1, str2) != -1){
                long long cnt = check(str1, str2);
                ans = min(ans, cnt + f(i+k, source, target, n, dp));
            }
        }
        return dp[i] = ans;
    }

    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
    
        int n = source.size();
        int m = original.size();
        int cnt = 0;
        for(int i=0; i<m; i++){
            if(!mp.count(original[i])){
                mp[original[i]] = cnt;
                cnt++;
            }
            if(!mp.count(changed[i])){
                mp[changed[i]] = cnt;
                cnt++;
            }
        }
        dis.resize(cnt, vector<long long>(cnt, MAXI));
        for(int i=0; i<cnt; i++){
            dis[i][i] = 0;
        }
        for(int i=0; i<m; i++){
            dis[mp[original[i]]][mp[changed[i]]] = min(dis[mp[original[i]]][mp[changed[i]]], (long long)cost[i]); 
        }
        for (int k = 0; k < cnt; k++) {
            for (int i = 0; i < cnt; i++) {
                for (int j = 0; j < cnt; j++) {
                    if(dis[i][k] != MAXI && dis[k][j]!= MAXI)
                    dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
                }
            }
        }
        for(auto &i: original) st.insert(i.size());

        vector<long long> dp(n, -1);
        long long ans = f(0, source, target, n, dp);
        return ans < 0 || ans >= MAXI ? -1 : ans;
    }
};