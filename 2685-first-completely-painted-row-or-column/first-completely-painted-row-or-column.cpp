class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        vector<int> freq1(n, 0);
        vector<int> freq2(m, 0);

        map<int,pair<int,int>> mp;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mp[mat[i][j]] = {i, j};
            }
        }

        for(int i=0; i<m*n; i++){
            int ind1 = mp[arr[i]].first;
            int ind2 = mp[arr[i]].second;
            freq1[ind1]++;
            freq2[ind2]++;

            if(freq1[ind1] == m || freq2[ind2] == n){
                return i;
            }
        }
        return -1;
    }
};