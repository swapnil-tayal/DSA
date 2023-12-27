class Solution {
public:
    
    int minCost(string colors, vector<int>& neededTime) {
        
        int n = colors.size();
        int i = 0;
        int ans = 0;
        
        while(i < n){
            
            char ch = colors[i];
            int cnt = 0;
            priority_queue<int, vector<int>, greater<int>> pq;
            
            while(i < n && colors[i] == ch){
                pq.push(neededTime[i]);
                cnt++;
                i++;
            }
            if(cnt >= 2){
                while(pq.size() > 1){
                    ans += pq.top();
                    pq.pop();
                }
            }
        }
        return ans;
    }
};