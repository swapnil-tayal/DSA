class Solution {
public:

    vector<int> f(int n) {
        vector<int>divisors;
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                if (n / i == i) {
                    divisors.push_back(i) ;
                }
                else {
                    divisors.push_back(i) ;
                    divisors.push_back(n/i) ;
                }
            }
        }
        return divisors;
    }

    int sumFourDivisors(vector<int>& nums) {
        
        int ans = 0;
        for(auto &i: nums){
            vector<int> a = f(i);
            if(a.size() == 4){
                for(auto &k: a) ans += k;
            }
        }
        return ans;
    }
};