class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        
        map<int,int> mp;
        set<int> dryDay;
        int n = rains.size();
        vector<int> a;
        vector<int> ans(n, -1);
        
        for(int i=0; i<n; i++){

            if(rains[i] == 0) dryDay.insert(i);
            else{
                if(mp.count(rains[i]) == 0) mp[rains[i]] = i;
                else{
                    auto ind = dryDay.lower_bound(mp[rains[i]]);
                    if(ind == dryDay.end()) return {};
                    else{
                        ans[*ind] = rains[i];
                        dryDay.erase(*ind);
                        mp[rains[i]] = i;
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            if(rains[i] == 0 and ans[i] == -1){
                ans[i] = 1;
            }
        }
        return ans;
    }
};