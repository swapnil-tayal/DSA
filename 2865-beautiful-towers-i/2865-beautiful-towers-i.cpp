class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        
        int n = maxHeights.size();
        long long ans = 0;
        
        for(int i=0; i<n; i++){
            
            long long sum = maxHeights[i];
            int maxi = sum;
            int p = i-1;
            while(p >= 0){
                sum += min(maxHeights[p], maxi);
                maxi = min(maxHeights[p], maxi);
                p--;
            }
            p = i+1;
            maxi = maxHeights[i];
            while(p < n){
                sum += min(maxHeights[p], maxi);
                maxi = min(maxHeights[p], maxi);
                p++;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};