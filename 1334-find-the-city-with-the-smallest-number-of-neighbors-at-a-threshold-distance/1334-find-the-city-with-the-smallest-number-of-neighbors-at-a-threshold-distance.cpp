bool cmp(pair<int,int> &p1, pair<int,int> &p2){
    if(p1.first == p2.first) return p1.second > p2.second;
    else return p1.first < p2.first;
}

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> matrix(n, vector<int>(n, 1e9));
        for(auto &i: edges){
            matrix[i[0]][i[1]] = i[2];
            matrix[i[1]][i[0]] = i[2];
        }
        
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(i == j) matrix[i][j] = 0;           
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
        vector<pair<int,int>> num;
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(i == j) continue;
                if(matrix[i][j] <= distanceThreshold) cnt++;
            }
            num.push_back({ cnt, i });
        }
        sort(num.begin(), num.end(), cmp);
        return num[0].second;
    }
};