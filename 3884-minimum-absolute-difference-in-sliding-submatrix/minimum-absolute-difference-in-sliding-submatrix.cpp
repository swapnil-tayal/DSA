class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans;

        for(int i=0; i<n-k+1; i++){

            vector<int> col;
            for(int j=0; j<m-k+1; j++){

                vector<int> a;
                for(int p=i; p<i+k; p++){
                    for(int q=j; q<j+k; q++){
                        a.push_back(grid[p][q]);
                    }
                }
                sort(a.begin(), a.end());
                int mini = 1e9;
                for(int x=0; x<a.size()-1; x++){
                    if(a[x+1] == a[x]) continue;
                    mini = min(mini, a[x+1]-a[x]);
                }
                col.push_back(mini == 1e9 ? 0 : mini);
            }
            ans.push_back(col);
        }
        return ans;
    }
};