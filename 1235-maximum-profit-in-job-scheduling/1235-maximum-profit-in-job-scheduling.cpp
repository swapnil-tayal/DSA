bool cmp(vector<int> &a1, vector<int> &a2){
    return a1[0] < a2[0];
}

class Solution {
    vector<int> str;
public:
    
    int f(int i, vector<vector<int>> &arr, vector<int> &dp){
        
        if(i >= arr.size()) return 0;
        if(dp[i] != -1) return dp[i];
        
        int skipDay = f(i+1, arr, dp);
        
        int ind = lower_bound(str.begin(), str.end(), arr[i][1]) - str.begin();
        int pickDay = arr[i][2] + f(ind, arr, dp);
        
        return dp[i] = max(skipDay, pickDay);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        vector<vector<int>> arr;
        int n = startTime.size();
        for(int i=0; i<n; i++){
            arr.push_back({ startTime[i], endTime[i], profit[i] });
        }
        
        sort(arr.begin(), arr.end(), cmp);
        for(auto i: arr) str.push_back(i[0]);
        vector<int> dp(n, -1);
        return f(0, arr, dp);
    }
};