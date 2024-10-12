class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        vector<int> a(1e6+10, 0);
        for(auto &i: intervals){
            a[i[0]]++;
            a[i[1]+1]--;
        }
        vector<int> pre(1e6+10, 0);
        pre[0] = a[0];
        int ans = 0;
        for(int i=1; i<1e6+10; i++){
            pre[i] = pre[i-1] + a[i];
            ans = max(ans, pre[i]);
        }
        return ans;
    }
};