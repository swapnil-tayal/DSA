class Solution {
public:
    
    long long getcount(long long n, int k){
        long long res = (n >> (k + 1)) << k; 
        if ((n >> k) & 1){
            res += n & ((1ll << k) - 1);
        }return res;
    }
    
    bool f(long long num, long long k, int x){
        
        long long val = 0;
        for(int i=1; i<=63; i++){
            
            if(i%x != 0) continue;
            val += getcount(num+1, i-1);
            
        }
        // if(num == 7) cout<<val<<'\n';
        return val <= k;
    }
    
    long long findMaximumNumber(long long k, int x) {
        
        long long s = 0;
        long long e = 1e16;
        long long ans = 0;
        
        // cout<<f(6, k, x)<<'\n';
        
        while(s <= e){
            
            long long mid = (s+e)/2;
            if(f(mid, k, x)){
                ans = mid;
                s = mid+1;
            }else e = mid-1;
        }
        return ans;
    }
};