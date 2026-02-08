class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        int n = nums.size();
        int i = 0;
        int j = 0;
        priority_queue<pair<int,int>> pqMax;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pqMin;
        set<int> st;
        long long ans = 0;

        while(j < n){

            pqMax.push({ nums[j], j });
            pqMin.push({ nums[j], j });
            while(st.count(pqMin.top().second)) pqMin.pop();
            while(st.count(pqMax.top().second)) pqMax.pop();
            long long cost = 1ll * (pqMax.top().first - pqMin.top().first) * (j-i+1);

            if(cost <= k) ans += j-i+1;
            else{
                while(cost > k){
                    st.insert(i);
                    i++;
                    while(st.count(pqMin.top().second)) pqMin.pop();
                    while(st.count(pqMax.top().second)) pqMax.pop();
                    cost = 1ll * (pqMax.top().first - pqMin.top().first) * (j-i+1);
                }
                if(cost <= k) ans += j-i+1;
            }
            j++;
        }
        return ans;
    }
};