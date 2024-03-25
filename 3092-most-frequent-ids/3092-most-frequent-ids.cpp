class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        
        map<int, long long> mp;
        priority_queue<pair<long long,int>> pq;
        
        int n = nums.size();
        vector<long long> ans(n);
    
        for(int i=0; i<n; i++){
            
            mp[nums[i]] += freq[i];
            pq.push({ mp[nums[i]], nums[i] });
            while(!pq.empty() and mp[pq.top().second] != pq.top().first){
                pq.pop();
            }
            if(pq.empty()) ans[i] = 0;
            else ans[i] = pq.top().first;
        }
        return ans;
    }
};