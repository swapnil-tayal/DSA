class Solution {
public:
    
    int minCost(string colors, vector<int>& neededTime) {
        
        int n = colors.size();
        int i = 0;
        int ans = 0;
        
        while(i < n){
            
            char ch = colors[i];
            int cnt = 0;
            int maxCost = 0;
            int totalCost = 0;
            
            while(i < n && colors[i] == ch){
                maxCost = max(maxCost, neededTime[i]);
                totalCost += neededTime[i];
                cnt++;
                i++;
            }
            if(cnt >= 2){
                ans += totalCost - maxCost;
            }
        }
        return ans;
    }
};