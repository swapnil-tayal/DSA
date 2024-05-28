class Solution{
    
    int f(string &s, string &t, int maxCost, int mid){
        
        int n = s.size();
        int i = 0;
        int j = 0;
        int cost = 0;
        
        while(j < n){
            
            cost += abs(s[j] - t[j]);
            if(j-i+1 < mid)  j++;
            else{
                
                // cout<<cost<<' ';
                if(cost <= maxCost) return 1;
                cost -= abs(s[i]-t[i]);
                i++;
                j++;
            }
        }
        return 0;
    }
    
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int n = s.size();
        int str = 0;
        int e = n;
        int ans = 0;
        
        cout<<f(s, t, maxCost, 3)<<'\n';
        
        while(str <= e){
            
            int mid = (str+e)/2;
            if(f(s, t, maxCost, mid)){
                ans = mid;   
                str = mid+1;
            }else e = mid-1;
            
        }
        return ans;
    }
};