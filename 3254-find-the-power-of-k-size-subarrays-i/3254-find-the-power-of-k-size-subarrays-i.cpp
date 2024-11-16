class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        
        deque<int> dq;
        priority_queue<pair<int,int>> pq;
        int n = nums.size();
        
        if(k == 1) return nums;
        
        int i = 0;
        int j = 0;
        vector<int> ans;
        int checks = 0;
        
        while(j < n){
            
            if(dq.size() == 0) dq.push_front(nums[j]);
            else{
                if(dq.front() + 1 != nums[j]) checks++;
                dq.push_front(nums[j]);
            }
            pq.push({ nums[j], j });
            
            if(j-i+1 < k) j++;
            else{
                
                while(!pq.empty() and pq.top().second < i) pq.pop();
                if(checks == 0) ans.push_back(pq.top().first);
                else ans.push_back(-1);
                int last1 = dq.back();
                dq.pop_back();
                if(last1 + 1 != dq.back()) checks--;
                i++;
                j++;
            }
        }
        return ans;
    }
};