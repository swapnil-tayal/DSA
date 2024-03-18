bool cmp(vector<int> &a1, vector<int> &a2){
    return a1[1] < a2[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        int n = points.size();
        sort(points.begin(), points.end(), cmp);
    
        int curr = points[0][1];
        int cnt = 1;
        for(int i=1; i<n; i++){
            
            if(points[i][0] > curr){
                curr = points[i][1];
                cnt++;
            }
        }
        return cnt;
    }
};