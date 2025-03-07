class Solution {
    vector<int> a;
public:

    Solution(){
        int n = 1e6;
        a.resize(n+1, 0);
        a[1] = 1;
        for(long long i=2; i<=n; i++){
            for(long long j=i*i; j<=n; j+=i) a[j] = 1; 
        }
    }

    vector<int> closestPrimes(int left, int right) {
        int first = -1;
        int second = -1;
        int mini = 1e9;
        vector<int> ans = {-1, -1};
        for(int i=left; i<=right; i++){
            if(a[i] == 0){
                if(first == -1) first = i;
                else{
                    if(i - first < mini){
                        second = i;
                        ans = {first, second};
                        mini = second - first;
                    }
                    first = i;
                }
            }
        }
        return ans;
    }
};