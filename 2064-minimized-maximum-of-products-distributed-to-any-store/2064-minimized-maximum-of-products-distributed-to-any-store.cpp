class Solution {
public:
    
    int f(int mid, vector<int> &a, int n){
        
        int req = 0;
        for(auto &i: a){
            if(i <= mid) req++;
            else{
                req += (i+mid-1)/mid;
            }
        }
        return req <= n;
    }
    
    int minimizedMaximum(int n, vector<int>& a) {
        
        int s = 1;
        int e = *max_element(a.begin(), a.end());
        int ans = 0;
        
        while(s <= e){
            
            int mid = (s+e)/2;
            if(f(mid, a, n)){
                
                ans = mid;
                e = mid-1;
                
            }else s = mid+1;
        }
        return ans;
    }
};