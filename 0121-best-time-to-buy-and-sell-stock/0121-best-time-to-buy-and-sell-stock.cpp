class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<int> maxArr(n, 0);
        int maxi = prices[n-1];
        
        for(int i=n-1; i>=0; i--){
            maxi = max(maxi, prices[i]);
            maxArr[i] = maxi;
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, maxArr[i] - prices[i]);
        }
        return ans;
    }
};