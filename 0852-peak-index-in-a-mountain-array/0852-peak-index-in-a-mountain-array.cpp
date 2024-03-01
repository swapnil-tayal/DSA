class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int n = a.size();
        int s = 0;
        int e = n-1;
        
        if(n == 1) return 0;
        
        if(a[0] > a[1]) return 0;
        if(a[n-1] > a[n-2]) return n-1;
        
        while(s <= e){
            
            int mid = (s+e)/2;
            
            if(a[mid-1] > a[mid] and a[mid] > a[mid+1]) e = mid;
            else if(a[mid-1] < a[mid] and a[mid] < a[mid+1]) s = mid;
            else if(a[mid-1] > a[mid] and a[mid] < a[mid+1]) e = mid;
            else return mid;
        }
        return -1;
    }
};