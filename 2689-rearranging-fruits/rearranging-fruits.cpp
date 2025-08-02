class Solution {
    map<int,int> mp;
    map<int,int> mp1;
    map<int,int> mp2;
public:

    vector<int> findExtras(map<int,int> mp1, map<int,int> mp2){
        vector<int> extras;
        for(auto &i: mp1){
            int diff = i.second - mp2[i.first];
            if(diff == 0) continue;
            if(diff > 0){
                diff /= 2;
                while(diff-- > 0) extras.push_back(i.first);
            }
        }
        return extras;
    }

    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        
        for(auto &i: basket1) mp[i]++;
        for(auto &i: basket1) mp1[i]++;
        for(auto &i: basket2) mp[i]++;
        for(auto &i: basket2) mp2[i]++;

        for(auto &i: mp){
            if(i.second % 2) return -1;
        }

        vector<int> a1 = findExtras(mp1, mp2);
        vector<int> a2 = findExtras(mp2, mp1);

        // for(auto i: a1) cout<<i<<' ';
        // cout<<'\n';
        // for(auto i: a2) cout<<i<<' ';

        long long mini = 1e9;
        for(long long i: basket1) mini = min(mini, i);
        for(long long i: basket2) mini = min(mini, i);

        long long cnt = 0;
        vector<int> a;
        for(auto i: a1) a.push_back(i);
        for(auto i: a2) a.push_back(i);
        sort(a.begin(), a.end());

        for(int i=0; i<a1.size(); i++){
            cnt += min((long long)a[i], 2*mini);
        }
        return cnt;
    }
};

// 2 3 3 
// 1 1 4