bool cmp(vector<int> &a1, vector<int> &a2){
    if(a1[0] == a2[0]) return a1[1] >= a2[1];
    else return a1[0] < a2[0];
}

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        
        int n = points.size();
        sort(points.begin(), points.end(), cmp);
        
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int f = 0;
                if(x1 <= x2 and y1 >= y2){
                    f = 1;
                    for(int k=0; k<n; k++){
                        if(i == k || j == k) continue;
                        if(points[k][0] >= x1 and points[k][0] <= x2 and points[k][1] >= y2 and points[k][1] <= y1){
                            f = 0;
                        }
                    }
                
                }
                cnt += f;
            }
        }
        return cnt;
    }
};