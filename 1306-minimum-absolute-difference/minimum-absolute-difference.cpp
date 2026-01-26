class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        int ans = 1e9;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i=1; i<n; i++){
            ans = min(ans, abs(arr[i]-arr[i-1]));
        }
        vector<vector<int>> res;
        for(int i=1; i<n; i++){
            if(abs(arr[i]-arr[i-1]) == ans){
                res.push_back({arr[i-1], arr[i]});
            }
        }
        return res;
    }
};