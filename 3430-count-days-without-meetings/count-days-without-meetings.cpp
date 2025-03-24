class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& a) {
        
        sort(a.begin(), a.end());
        vector<vector<int>> ans;
        int n = a.size();
        
        int currMax = a[0][1];
        int currMin = a[0][0];
        
        for(int i=1; i<n; i++){
            
            if(currMax < a[i][0]){
                
                ans.push_back({ currMin, currMax });
                currMin = a[i][0];
            }
            currMax = max(currMax, a[i][1]);
        }
        ans.push_back({ currMin, currMax });
        return ans;
    }
    
    int countDays(int days, vector<vector<int>>& meetings) {
        
        int n = meetings.size();
        meetings = merge(meetings);
        
        int sum = 0;
        for(auto i: meetings){
            sum += i[1] - i[0] + 1;
        }
        return days-sum;
    }
};