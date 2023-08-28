class Solution {
public:
    int hIndex(vector<int>& a) {
        
        int n = a.size();
        int max = a[n-1];
        int ans = 0;
        
        for(int i=0; i<=max; i++){
            
            int ind = lower_bound(a.begin(), a.end(), i) - a.begin();
            int ind2 = upper_bound(a.begin(), a.end(), i) - a.begin();
            
            if(ind == a.size()) continue;
            if(n - ind >=i and n - ind2 <= i) ans = i;
            
        }
        return ans;
    }
};