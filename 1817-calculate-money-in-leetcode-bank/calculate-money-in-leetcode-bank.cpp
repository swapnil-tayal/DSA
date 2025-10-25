class Solution {
public:
    int totalMoney(int n) {
        int tweek = n/7;
        int ans = 0 ;
        ans += tweek * (7*4);
        ans += (7 * ((tweek)*(tweek-1)/2));
        int extra = n%7;
        ans += (tweek+extra)*(tweek+extra+1)/2 - (tweek)*(tweek+1)/2;
        return ans;
    }
};