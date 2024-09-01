class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        
        int n = queries.size();
        vector<int> a;
        for(auto &i: queries){
            a.push_back(abs(0-i[0]) + abs(0-i[1]));
        }
        priority_queue<int> pq;
        
        vector<int> ans(n, -1);
        for(int i=0; i<n; i++){
            pq.push(a[i]);
            if(pq.size() > k) pq.pop();
            if(pq.size() == k) ans[i] = pq.top();
        }
        return ans;
    }
};