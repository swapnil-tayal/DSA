class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> grid(n, vector<int>(m, 0));
        
        for(int j=0; j<m; j++){
            int i = n-1;
            while(i >= 0){
                if(matrix[i][j] == 0){
                    i--;
                    continue;
                }
                int cnt = 0;
                while(i >= 0 and matrix[i][j] == 1){
                    cnt++;
                    grid[i][j] = cnt;
                    i--;
                }
            }
        }
        
        // for(auto i: grid){
        //     for(auto j: i) cout<<j<<' ';
        //     cout<<'\n';
        // }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            
            vector<int> temp;
            for(int j=0; j<m; j++){
                temp.push_back(grid[i][j]);
            }
            sort(temp.rbegin(), temp.rend());
            for(int k=0; k<m; k++){
                ans = max(ans, temp[k]*(k+1));
            }
        }
        
        return ans;
    }
};