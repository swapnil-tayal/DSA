class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {
            if (a[1] != b[1])
                return a[1] < b[1];
            return a[0] > b[0];
        });
        int p1 = -1;
        int p2 = -1;
        int ans = 0;

        for(auto interval: intervals){
            int start = interval[0];
            int end = interval[1];
            if(p2 < start){
                ans += 2;
                p1 = end-1;
                p2 = end;
            }
            else if(p1 < start){
                ans++;
                p1 = p2;
                p2 = end;
            }
        }
        return ans;
    }
};