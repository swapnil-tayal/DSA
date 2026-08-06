class Solution {
public:

    bool f(int val, int t){
        int sum = 1;
        while(val > 0){
            sum *= (val % 10);
            val = val / 10;
        }
        return (sum % t) == 0;
    }

    int smallestNumber(int n, int t) {
        
        while(!f(n, t)) n++;
        return n;
    }
};