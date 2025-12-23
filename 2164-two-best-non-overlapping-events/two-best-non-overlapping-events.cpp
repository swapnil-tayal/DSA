class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        
        int n = events.size();
        sort(events.begin(), events.end());
        
        vector<int> maxi(n, 0);
        int value = 0;
        vector<int> start(n, 0);
        
        for(int i=n-1; i>=0; i--){
            start[i] = events[i][0];
            value = max(value, events[i][2]);
            maxi[i] = value;    
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            
            ans = max(ans, events[i][2]);
            int ind = lower_bound(start.begin(), start.end(), events[i][1]+1) - start.begin();
            if(ind == n) continue;
            
            // cout<<
            
            ans = max(ans, events[i][2] + maxi[ind]);            
            
        }
        return ans;
    }
};