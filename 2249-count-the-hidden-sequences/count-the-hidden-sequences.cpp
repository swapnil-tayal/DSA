class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        
        long long mini = 0;
        long long maxi = 0;
        int n = diff.size();
        long long last = 0;
        
        for(int i=0; i<n; i++){
            long long curr = last + diff[i];
            mini = min(mini, curr);
            maxi = max(maxi, curr);
            last = curr;
        }
        int d1 = upper-lower;
        int d2 = maxi-mini;
        if(d1 < d2) return 0;
        else{
            return d1-d2+1;
        }
    }
};