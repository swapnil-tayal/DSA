class Solution {
    int n;
public:

    void f(vector<vector<int>> &a, vector<int> str, vector<int> end){

        for(int i=str[0]; i<=end[0]; i++){
            for(int j=str[1]; j<=end[1]; j++){
                a[i][j]++;
            }
        }
    }

    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        this->n = n;
        vector<vector<int>> a(n, vector<int>(n, 0));
        for(auto i: queries){
            vector<int> str = {i[0], i[1]};
            vector<int> end = {i[2], i[3]};
            f(a, str, end);
        }
        return a;
    }
};