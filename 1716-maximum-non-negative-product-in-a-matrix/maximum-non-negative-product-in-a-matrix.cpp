class Solution {
    map<pair<long long, long long>, pair<long long, long long>> dp;
    long long mod = 1e9+7;
public:

    pair<long long, long long> f(int i, int j, vector<vector<int>> &grid){

        if(i >= grid.size() || j >= grid[0].size()) return {LLONG_MAX, LLONG_MIN};
        if(i == grid.size()-1 and j == grid[0].size()-1){
            return { grid[i][j], grid[i][j] };
        }
        if(dp.find({i, j}) != dp.end()) return dp[{i, j}];
        pair<long long, long long> down = f(i+1, j, grid);
        pair<long long, long long> right = f(i, j+1, grid);

        vector<long long> a;
        if(down.first != LLONG_MAX){
            a.push_back((down.first * grid[i][j]));
            a.push_back((down.second * grid[i][j]));
        }
        if(right.first != LLONG_MAX){
            a.push_back((right.first * grid[i][j]));
            a.push_back((right.second * grid[i][j]));
        }

        long long mini = *min_element(a.begin(), a.end());
        long long  maxi = *max_element(a.begin(), a.end());

        return dp[{i,j}] = {mini, maxi};

    }

    int maxProductPath(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        auto ans = f(0, 0, grid);
        return ans.second < 0 ? -1 : ans.second % mod;

    }
};