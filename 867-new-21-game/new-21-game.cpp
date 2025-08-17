// class Solution {
// public:

//     double f(double sum, int k, int n, int maxPts, vector<double> &dp){

//         if(sum >= k){
//             if(sum <= n) return double(1.0);
//             else return double(0.0);
//         }
//         if(dp[sum] != -1.0) return dp[sum];
//         double ans = 0;
//         for(double i=1; i<=maxPts; i++){
//             ans += f(sum + i, k, n, maxPts, dp);
//         }
//         return dp[sum] = ans / maxPts;
//     }

//     double new21Game(int n, int k, int maxPts) {
        
//         vector<double> dp(k+1, -1.0);
//         return f(0, k, n, maxPts, dp);
//     }
// };
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k + maxPts) return 1.0;

        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;
        double windowSum = 1.0, result = 0.0;

        for (int i = 1; i <= n; i++) {
            dp[i] = windowSum / maxPts;
            if (i < k) {
                windowSum += dp[i];
            } else {
                result += dp[i]; // finished states
            }
            if (i - maxPts >= 0) {
                windowSum -= dp[i - maxPts];
            }
        }
        return result;
    }
};