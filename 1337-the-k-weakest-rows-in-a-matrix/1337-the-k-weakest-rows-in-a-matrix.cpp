class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        vector<pair<int,int>> arr;
        for(int i=0; i<mat.size(); i++){
            
            int cnt = 0;
            for(int j=0; j<mat[0].size(); j++){
                cnt += mat[i][j];
            }
            arr.push_back({cnt, i});
        }
        sort(arr.begin(), arr.end());
        vector<int> ans;
        for(int i=0; i<k; i++) ans.push_back(arr[i].second);
        return ans;
    }
};