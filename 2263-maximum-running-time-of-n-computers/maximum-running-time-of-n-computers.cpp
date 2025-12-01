class Solution {
public:
    
    int f(long long mid , vector<int> &batteries, int n){
        
        long long cnt = 0;
        for(auto i: batteries){
            cnt += min((long long)i, mid);
        }
        return cnt >= mid*n;
    }
    
    long long maxRunTime(int n, vector<int>& batteries) {
        
        long long s = 0;
        long long e = 0;
        for(auto &i: batteries) e += i;
        
        long long ans = 0;
        sort(batteries.begin(), batteries.end());
        
        while(s <= e){
            
            long long mid = s + (e-s)/2;
            
            if(f(mid, batteries, n)){
                ans = mid;
                s = mid+1;
                
            }else e = mid-1;
        }
        return ans;
    }
};