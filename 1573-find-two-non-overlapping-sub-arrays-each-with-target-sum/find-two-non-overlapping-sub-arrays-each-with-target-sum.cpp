class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        
        vector<vector<int>> a;
        vector<int> fir;
        unordered_map<int,int> mp;
        int sum = 0;
        int ans = 1e9;
        mp[0] = -1;

        for(int i=0; i<arr.size(); i++){
            sum += arr[i];
            int val = sum - target;
            // cout<<sum<<' '<<val<<'\n';
            if(mp.count(val)){
                a.push_back({mp[val]+1, i});
                // cout<<i<<' '<<mp[val]+1<<'\n';
                fir.push_back(mp[val]+1);
            }
            mp[sum] = i;
        }

        int n = a.size();
        if(n <= 1) return -1;
        vector<int> sufMax(n, 0);
        sufMax[n-1] = a[n-1][1] - a[n-1][0] + 1;
 
        for(int i=n-2; i>=0; i--){
            sufMax[i] = min(sufMax[i+1], a[i][1]-a[i][0]+1);
        }
        // for(auto i: sufMax) cout<<i<<' ';
        // cout<<'\n';

        for(auto &i: a){

            int ind = lower_bound(fir.begin(), fir.end(), i[1]+1) - fir.begin();
            if(ind == n) continue;
            // cout<<ind<<' '<<sufMax[ind]<<'\n';
            ans = min(ans, i[1]-i[0]+1 + sufMax[ind]);
        }
        return ans == 1e9 ? -1 : ans;
    }
};