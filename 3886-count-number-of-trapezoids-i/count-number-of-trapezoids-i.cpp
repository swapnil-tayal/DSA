class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){
                return a.back() < b.back();
            });
        
        int i = 0;
        vector<long long> arr;
        while(i < points.size()){
            int cnt = 0;
            int y = points[i][1];
            while(i < points.size() and y == points[i][1]){
                i++;
                cnt++;
            }
            arr.push_back(cnt);
        }
        int n = arr.size();
        vector<long long> pre(n);
        long long ans = 0;
        // int res = 0;
        // for(auto i: arr) cout<<i<<' ';
        // cout<<'\n';
        for(int i=n-1; i>=0; i--){
            long long x = arr[i];
            x = x * (x-1) / 2;
            if(i+1 < n) ans = (ans + (x * pre[i+1])) % int(1e9+7);
            pre[i] = x;
            if(i+1 < n) pre[i] += pre[i+1];
            // res += ans;
        }
        return ans;
    }
};