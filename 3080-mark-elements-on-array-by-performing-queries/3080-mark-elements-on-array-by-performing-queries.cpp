struct PairComparator {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        // Compare first elements
        if (p1.first != p2.first)
            return p1.first > p2.first; // Ascending order for first elements
        // If first elements are equal, compare second elements
        return p1.second > p2.second; // Ascending order for second elements
    }
};

class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        
        long long sum = 0;
        for(auto i: nums) sum += i;
        
        int n = nums.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, PairComparator> pq;
        for(int i=0; i<n; i++){
            pq.push({ nums[i], i });
        }
        
        set<int> rem;
        int m = queries.size();
        vector<long long> ans(m, 0);
        
        for(int i=0; i<m; i++){
            
            if(rem.count(queries[i][0]) == 0){
                sum -= nums[queries[i][0]];
                rem.insert(queries[i][0]);
            }
            
            
            int k = queries[i][1];
            while(!pq.empty()){
                
                if(k == 0) break;
                
                if(rem.count(pq.top().second)) pq.pop();
                else{
                    sum -= pq.top().first;
                    rem.insert(pq.top().second);
                    pq.pop();
                    k--;
                }
            }
            ans[i] = sum;
        }
        return ans;
    }
};