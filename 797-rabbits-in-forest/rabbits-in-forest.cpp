class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> mp;
        for(auto i: answers) mp[i]++;
        int ans = 0;
        for(auto &i: mp){
            int val = i.first;
            int cnt = i.second;
            ans += ((cnt+val)/(val+1)) * (val+1);
        }
        return ans;
    }
};