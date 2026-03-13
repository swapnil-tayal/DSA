class Solution {
public:

    int f(long long t, int ht, vector<int> &a){

        long long totalH = 0;
        for(auto &i: a){

            long long left = 0; long long right = 1e6;
            while(left <= right){
                long long mid = left + (right - left) / 2;
                if(i * mid * (mid+1) / 2 <= t) left = mid+1;
                else right = mid-1;
            }
            totalH += right;
            if(totalH >= ht) return 1;
        }
        return totalH >= ht;
    }

    long long minNumberOfSeconds(int ht, vector<int>& a) {
        
        long long s = 0;
        long long e = 1e18;
        long long ans = 0;

        while(s <= e){

            long long mid = s + (e - s) / 2;
            if(f(mid, ht, a)){
                ans = mid;
                e = mid-1;
            }else s = mid+1;
        }
        return ans;
    }
};