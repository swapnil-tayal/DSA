class Solution {
    vector<int> starts;
    vector<vector<pair<long long, vector<int>>>> dp;
public:

    pair<long long, vector<int>> f(int i, int cnt, vector<vector<int>> &a){

        if(i == a.size() || cnt == 0) return {0, {}};
        if(dp[i][cnt].first != -1) return dp[i][cnt];

        int next = lower_bound(starts.begin(), starts.end(), a[i][1]+1) - starts.begin();
        auto pick = f(next, cnt-1, a);
        pick.first += a[i][2];
        pick.second.push_back(a[i][3]);
        auto npick = f(i+1, cnt, a);

        sort(pick.second.begin(), pick.second.end());
        sort(npick.second.begin(), npick.second.end());

        if(pick.first > npick.first) return dp[i][cnt] = pick;
        else if(pick.first < npick.first) return dp[i][cnt] = npick;
        else{
            if(pick.second < npick.second) return dp[i][cnt] = pick;
            else return dp[i][cnt] = npick;
        }
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        dp.assign(n, vector<pair<long long, vector<int>>>(5, {-1, {}}));
        for(int i=0; i<n; i++){
            intervals[i].push_back(i);
        }
        sort(intervals.begin(), intervals.end());
        for(auto &i: intervals){
            starts.push_back(i[0]);
        }
        return f(0, 4, intervals).second;
    }
};