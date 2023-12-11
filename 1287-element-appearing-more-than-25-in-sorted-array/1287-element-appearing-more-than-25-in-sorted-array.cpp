class Solution {
public:
    int findSpecialInteger(vector<int>& a) {
        
        int n = a.size();
        if(n == 1) return a[0];
        int k = (n) / 2;
        k = (k)/2;
        cout<<k<<' ';
        
        for(int i=0; i<n; i++){
            
            if(i+k >= n) return -1;
            if(a[i] == a[i+k]) return a[i];
        }
        return -1;
    }
};