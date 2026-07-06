class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            if(a[0] == b[0]) return a[1] > b[1];
            else return a[0] < b[0];
        });

        int start = intervals[0][0];
        int end = intervals[0][1];
        int cnt = 1;

        for(int i=1; i<n; i++){

            if(intervals[i][0] > start && intervals[i][1] > end){
                start = intervals[i][0];
                end = intervals[i][1];
                cnt++;
            }
            else if(intervals[i][0] >= start and intervals[i][1] <= end){
                continue;
            }
        }
        return cnt;
    }
};