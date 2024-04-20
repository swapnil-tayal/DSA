class Solution {
    int n,m;
public:
    
    vector<int> f(int x, int y, vector<vector<int>> &land){
        
        int i = x;
        int j = y;
        vector<int> arr(4, 0);
        arr[0] = x;
        arr[1] = y;
        
        while(i < n and land[i][j] == 1){
            i++;
        }
        arr[2] = i-1;
        i = x;
        while(j < m and land[i][j] == 1){
            j++;
        }
        arr[3] = j-1;
        
        for(int i=arr[0]; i<=arr[2]; i++){
            for(int j=arr[1]; j<=arr[3]; j++){
                land[i][j] = 0;
            }
        }
        return arr;
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        this->n = land.size();
        this->m = land[0].size();
        vector<vector<int>> ans;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(land[i][j] == 1){
                    vector<int> d = f(i, j, land);
                    ans.push_back(d);
                }
            }
        }
        return ans;
    }
};