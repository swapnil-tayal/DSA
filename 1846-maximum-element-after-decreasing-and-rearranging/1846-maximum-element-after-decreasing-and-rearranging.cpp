class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        int n = arr.size();
        arr[0] = 1;
        for(int i=1; i<n; i++){
            if(arr[i] - arr[i-1] > 1){
                arr[i] = arr[i-1]+1;
            }
        }
        int ans = 0;
        for(auto &i: arr) ans = max(ans, i);
        return ans;
    }
};