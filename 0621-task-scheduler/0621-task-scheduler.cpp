class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        int maxCnt = 0;
        map<char,int> mp;
        for(auto i: tasks){
            mp[i]++;
            maxCnt = max(maxCnt, mp[i]);
        }
        
        int ans = (maxCnt-1) * (n+1);
        for(auto i: mp){
            ans += (i.second == maxCnt);
        }
        return max((int)tasks.size(), ans);
    }
};