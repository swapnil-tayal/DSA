class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& a) {
        
        map<int,vector<int>> mpx, mpy;

        for(int i=0; i<a.size(); i++){
            mpx[a[i][0]].push_back(a[i][1]);
            mpy[a[i][1]].push_back(a[i][0]);
        }
        for(auto &i: mpx) sort(i.second.begin(), i.second.end());
        for(auto &i: mpy) sort(i.second.begin(), i.second.end());

        int ans = 0;
        for(auto &i: a){

            int x = i[0];
            int y = i[1];
            int cnt = 0;
            int ind1 = lower_bound(mpx[x].begin(), mpx[x].end(), y) - mpx[x].begin();
            if(ind1-1 >= 0 and ind1+1 < mpx[x].size()) cnt++;
            int ind2 = lower_bound(mpy[y].begin(), mpy[y].end(), x) - mpy[y].begin();
            if(ind2-1 >= 0 and ind2+1 < mpy[y].size()) cnt++;

            // if(x == 2 and y == 2){
            //     for(auto k: mpx[x]) cout<<k<<' ';
            //     cout<<'\n';
            //     for(auto k: mpy[y]) cout<<k<<' ';
            //     cout<<'\n';
            // }

            if(cnt == 2) ans++;
            
        }
        return ans;
    }
};