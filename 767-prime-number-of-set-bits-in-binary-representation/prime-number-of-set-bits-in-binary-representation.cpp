class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i < n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        
        int ans = 0;
        for(int i=left; i<=right; i++){
            bitset<64> it(i);
            int ones = 0;
            for(int k=0; k<64; k++) ones += (it[k]==1);
            ans += isPrime(ones); 
        }
        return ans;
    }
};