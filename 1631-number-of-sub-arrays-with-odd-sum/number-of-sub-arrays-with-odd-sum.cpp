class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        
        int sum = 0;
        int even = 1;
        int odd = 0;
        int n = arr.size();
        long long ans = 0;

        for(int i=0; i<n; i++){

            sum += arr[i];

            if(sum % 2 == 0) ans += odd;
            else ans += even;
            ans %= int(1e9+7);

            if(sum % 2 == 0) even++;
            else odd++;
            
        }
        return ans;
    }
};