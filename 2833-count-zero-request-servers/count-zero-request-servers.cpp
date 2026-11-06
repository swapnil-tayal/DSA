class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });

        vector<pair<int,int>> q;
        for(int i = 0; i < queries.size(); i++){
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        unordered_map<int,int> mp;
        vector<int> ans(queries.size());

        int i = 0;
        int j = 0;
        int m = logs.size();

        for(auto &it : q){

            int t = it.first;
            int idx = it.second;

            while(j < m && logs[j][1] <= t){
                mp[logs[j][0]]++;
                j++;
            }

            while(i < j && logs[i][1] < t-x){
                mp[logs[i][0]]--;

                if(mp[logs[i][0]] == 0){
                    mp.erase(logs[i][0]);
                }
                i++;
            }
            ans[idx] = n - mp.size();
        }
        return ans;
    }
};