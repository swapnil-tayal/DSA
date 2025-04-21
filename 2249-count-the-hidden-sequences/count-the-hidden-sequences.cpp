class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        
        long long mini = 0;
        long long maxi = 0;
        int n = diff.size();
        vector<long long> arr(n+1);
        arr[0] = 0;
        
        for(int i=0; i<n; i++){
            arr[i+1] = arr[i] + diff[i];
            mini = min(mini, arr[i+1]);
            maxi = max(maxi, arr[i+1]);
        }
        int d1 = upper-lower;
        int d2 = maxi-mini;
        if(d1 < d2) return 0;
        else{
            return d1-d2+1;
        }
    }
};