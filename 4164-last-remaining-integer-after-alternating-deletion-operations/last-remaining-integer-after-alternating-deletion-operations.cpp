class Solution {
    public:
    long lastInteger(long n) {

        long first = 1;
        long last = n;
        long skip = 1;
        int left = 1;
        while(n>1){
            if(left) {
                if(n%2==0) last = last - skip;
            }
            else {
                if(n%2==0) first = first + skip;
            }
            n = (n+1)/2;
            skip = skip*2;
            left = 1-left;
        }
        return first;
    }
};