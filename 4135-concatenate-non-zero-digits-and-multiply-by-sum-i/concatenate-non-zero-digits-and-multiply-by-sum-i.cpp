class Solution {
public:
    long long sumAndMultiply(int n) {

        long long x = 0;
        int sum = 0;
        int pos = 1;
        
        while(n > 0){

            int d = n % 10;
            n = n/10;
            if(d == 0) continue;
            x = d * pos + x;
            pos *= 10;
            sum += d;

        }
        return x * sum;
    }
};