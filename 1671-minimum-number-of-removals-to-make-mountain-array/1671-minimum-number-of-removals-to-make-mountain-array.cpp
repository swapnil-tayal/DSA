class Solution {
public:
    int minimumMountainRemovals(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp1(n, 1), dp2(n, 1);
    
        for(int i=1; i<n; i++){
            for(int prev=0; prev<i; prev++){

                if(arr[i] > arr[prev] and dp1[i] < dp1[prev] + 1){
                    dp1[i] = dp1[prev] + 1;
                }
            }
            for(int prev=n-1; prev>n-i-1; prev--){

                if(arr[n-i-1] > arr[prev] and dp2[n-i-1] < dp2[prev] + 1){
                    dp2[n-i-1] = dp2[prev] + 1;
                }
            }
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            if(dp1[i] > 1 and dp2[i] > 1){
                ans = max(ans, dp1[i] + dp2[i] - 1);
            }   
        }
        
        return n-ans;
    }
};