class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<int> a(n);
        for(int i=0; i<n; i++) a[i] = i;
        sort(a.begin(), a.end(), [&](int i, int j){
            return nums[i] < nums[j];
        });
        vector<int> pos(n);
        for (int i = 0; i < n; i++){
            pos[a[i]] = i;
        }
        sort(nums.begin(), nums.end());

        int m = __lg(n)+1;
        vector<vector<int>> f(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            int ind = upper_bound(nums.begin(), nums.end(), nums[i] + maxDiff) - nums.begin();
            f[i][0] = ind-1;
        }
        for(int j=1; j<m; j++){
            for(int i=0; i<n; i++){
                f[i][j] = f[f[i][j-1]][j-1];
            }
        }
        vector<int> comp(n, 0);
        for (int i = 1; i < n; i++) {
            comp[i] = comp[i - 1];
            if (nums[i] - nums[i - 1] > maxDiff){
                comp[i]++;
            }
        }

        vector<int> ans;
        for(auto &i: queries){

            int u = pos[i[0]];
            int v = pos[i[1]];
            if(u > v) swap(u, v);

            if(u == v){
                ans.push_back(0);
                continue;
            }
            if (comp[u] != comp[v]) {
                ans.push_back(-1);
                continue;
            }

            int steps = 0;
            for(int k=m-1; k>=0; k--){
                if(f[u][k] < v){
                    u = f[u][k];
                    steps += pow(2, k);
                }
            }
            ans.push_back(steps+1);
        }
        return ans;
    }
};