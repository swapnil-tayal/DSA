class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        
        int n = nums.size();
        map<int,int> mp;
        priority_queue<int> pq;
        for(auto i: nums){
            mp[i]++;
        }
        for(auto i: mp){
            pq.push(i.first);
        }
        int ans = 0;
        
        while(pq.size() > 1){
            
            int x = mp[pq.top()];
            pq.pop();
            ans += x;
            mp[pq.top()] += x;
        }
        return ans;
    }
};