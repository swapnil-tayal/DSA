class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        map<int,int> mp;
        priority_queue<int> pq;
        
        int i = 0;
        int j = 0;
        vector<int> ans;
        int n = nums.size();
        
        while(j < n){
            
            pq.push(nums[j]);
            
            if(j-i+1 < k) j++;
            else{
                // cout<<pq.top()<<' ';
                while(!pq.empty() and mp.find(pq.top()) != mp.end()){
                    mp[pq.top()]--;
                    if(mp[pq.top()] == 0) mp.erase(pq.top());
                    pq.pop();
                }
                ans.push_back(pq.top());
                mp[nums[i]]++;
                i++;
                j++;
            }
        }
        return ans;
    }
};