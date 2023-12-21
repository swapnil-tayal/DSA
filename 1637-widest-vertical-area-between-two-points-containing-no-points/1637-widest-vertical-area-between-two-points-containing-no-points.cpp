bool cmp(vector<int> &a1, vector<int> &a2){
    return a1[0] <= a2[0];
}

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        
        sort(points.begin(), points.end(), cmp);
        int ans = 0;
        int n = points.size();
        
        for(int i=1; i<n; i++){
            ans = max(ans, points[i][0] - points[i-1][0]);
        }
        return ans;
    }
};