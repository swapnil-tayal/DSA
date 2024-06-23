class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int n = nums.size();
        priority_queue<pair<int,int>> maxpq;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minpq;
        
        int i = 0;
        int j = 0;
        int ans = 0;
        set<int> st;
        
        while(j < n){
            
            minpq.push({ nums[j], j });
            maxpq.push({ nums[j], j });
        
            int maxi = maxpq.top().first;
            int mini = minpq.top().first;
            
            if(maxi - mini <= limit){
                ans = max(ans, j-i+1);
                j++;
            
            }else{
                
                while(maxpq.top().first - minpq.top().first > limit){
                    st.insert(i);
                    while(!maxpq.empty() and st.count(maxpq.top().second)) maxpq.pop();
                    while(!minpq.empty() and st.count(minpq.top().second)) minpq.pop();
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};