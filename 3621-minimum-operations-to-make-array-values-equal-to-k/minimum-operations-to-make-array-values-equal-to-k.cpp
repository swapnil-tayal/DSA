class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        map<int,int> mp;
        for(auto i: nums) mp[i]++; 
        int cnt = 0;
        for(auto i: mp){
            if(i.first < k) return -1;
            else if(i.first > k) cnt++;
        }
        return cnt;
    }
};