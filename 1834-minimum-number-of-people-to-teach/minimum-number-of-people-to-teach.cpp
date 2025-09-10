class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        
        map<int,set<int>> mp;
        int cnt = 1;
        for(auto &i: languages){
            for(auto &k: i){
                mp[k].insert(cnt);
            }cnt++;
        }
        set<int> learners;
        for(auto &i: friendships){
            int found = false;
            for(auto &k: mp){
                if(k.second.count(i[0]) && k.second.count(i[1])){
                    found = true;
                    break;
                }
            }
            if(found == false){
                learners.insert(i[0]);
                learners.insert(i[1]);
            }
        }
        int ans = 1e9;
        for(int i=1; i<=n; i++){
            int cnt = 0;
            for(auto &k: learners){
                if(mp[i].count(k) == 0) cnt++;
            }
            ans = min(ans, cnt);
        }
        return ans == 1e9 ? 0 : ans;
    }
};