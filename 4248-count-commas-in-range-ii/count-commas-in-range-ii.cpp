class Solution {
public:
    long long countCommas(long long n) {
        
        if(n < 1000) return 0;
        long long x = 10000;
        long long commas = 0;
        while(true){

            long long last = x/10;
            long long c = (to_string(x-1).size() - 1) / 3;

            if(n >= x){
                commas += c * (x - last);
                x = x*10;

            }else{
                n -= (last-1);
                commas += c * n; 
                break;
            }
        }
        return commas;
    }
};

// 1,000,000,000,000,000
// 999 = 0 = 3
// 1,000 = 1 = 4
// 10,000 = 1 = 5
// 100,000 = 1 = 6
// 1,000,000 = 2 = 7