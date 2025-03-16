class Solution {
public:

    int f(vector<int> &a, long long k, int cars){

        int n = a.size();
        long long cnt = 0;
        for(int i=0; i<n; i++){
            long long x = k/a[i];
            int sq = sqrt(x);
            cnt += sq;
        }
        return cnt >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        
        long long s = 1;
        long long e = 1e16;
        long long ans = 0;

        // cout<<f(ranks, 16, cars)<<'\n';
        // return 1;

        while(s <= e){
            long long mid = (s+e)/2;
            if(f(ranks, mid, cars)){
                ans = mid;
                e = mid-1;
            }else s = mid+1;
        }
        return ans;
    }
};