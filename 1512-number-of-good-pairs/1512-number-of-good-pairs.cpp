class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        map<int,int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        
        int cnt = 0;
        for(auto i: mp){  
            cnt += (i.second*(i.second-1))/2;
        }
        return cnt;
    }
};