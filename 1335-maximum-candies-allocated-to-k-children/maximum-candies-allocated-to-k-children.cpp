class Solution {
public:

    int f(vector<int> &a, long long mid, long long k){
        int n = a.size();
        long long x = 0;
        for(auto &i: a){
            x += (long long)(i/mid);
        }
        return x >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        
        int s = 1;
        int e = 1e8;
        int ans = 1;

        long long sm = 0;
        for(auto &i: candies) sm += i;
        if(sm < k) return 0;

        while(s <= e){
            int mid = (s+e)/2;
            if(f(candies, mid, k)){
                ans = mid;
                s = mid+1;
            }else e = mid-1;
        }
        return ans;
    }
};