class Solution{
public:

    
    bool f(long long t, int h, vector<int>& wt){
        long long totalH = 0;

        for (int w : wt) {
            long long left = 0, right = 1e6;
            while (left <= right) {
                long long mid = left + (right - left) / 2;
                if (w * mid * (mid + 1) / 2 <= t) left = mid + 1;
                else right = mid - 1;
            }
            totalH += right;
            if (totalH >= h) return true;
        }
        return totalH >= h;
    }
    
    long long minNumberOfSeconds(int x, vector<int>& a) {
        
        long long s = 0;
        long long e = 1e18;
        long long ans = 0;
        while(s <= e){
            
            long long mid = s+(e-s)/2;
            if(f(mid, x, a)){
                
                ans = mid;
                e = mid-1;
                
            }else s = mid+1;
        }
        return ans;
    }
};