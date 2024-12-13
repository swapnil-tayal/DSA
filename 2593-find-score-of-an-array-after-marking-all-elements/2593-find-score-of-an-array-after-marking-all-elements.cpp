class Solution {
public:
    long long findScore(vector<int>& nums) {
        
        long long ans = 0;
        set<int> st;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        
        for(int i=0; i<nums.size(); i++){
            pq.push({ nums[i], i });
        }
        
        while(!pq.empty()){
            
            if(st.count(pq.top().second)) pq.pop();
            else{
                ans += pq.top().first;
                st.insert(pq.top().second-1);
                st.insert(pq.top().second+1);
                pq.pop();
            }
        }
        return ans;
    }
};