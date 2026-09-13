class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        
        vector<pair<int, int>> m1;
        vector<pair<int, int>> m2;
        int n = img1.size();
        
        for(int i=0; i<n ;i++){
            for(int j=0; j<n; j++){
                if(img1[i][j] == 1) m1.push_back({i, j});
                if(img2[i][j] == 1) m2.push_back({i, j});
            }
        }
        
        map<pair<int, int>, int> mp;
        int res = 0;
        for(auto [i1, j1]: m1){
            for(auto [i2, j2]: m2){
                
                mp[{i1-i2, j1-j2}]++;
                res = max(res, mp[{i1-i2, j1-j2}]);
                
            }
        }
        return res;
    }
};