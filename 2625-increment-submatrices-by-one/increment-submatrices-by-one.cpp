class Solution {
    int n;
public:

    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        this->n = n;
        vector<vector<int>> a(n, vector<int>(n, 0));
        for(auto i: queries){
            int s1 = i[0];
            int e1 = i[1];
            int s2 = i[2];
            int e2 = i[3];
            a[s1][e1]++;
            if(s2+1 < n) a[s2+1][e1]--;
            if(e2+1 < n) a[s1][e2+1]--;
            if(e2+1 < n and s2+1 < n) a[s2+1][e2+1]++;
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                a[i][j] += a[i-1][j];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=1; j<n; j++){
                a[i][j] += a[i][j-1];
            }
        }
        return a;
    }
};