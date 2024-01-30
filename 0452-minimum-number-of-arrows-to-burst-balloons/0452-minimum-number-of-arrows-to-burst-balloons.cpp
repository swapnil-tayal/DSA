bool cmp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end(), cmp);
        int n = points.size();
        
        int curr = points[0][1];
        int cnt = 1;
        for(int i=0; i<n; i++){
            if(points[i][0] > curr){
                curr = points[i][1];
                cnt++;
            }
        }
        return cnt;
    }
};