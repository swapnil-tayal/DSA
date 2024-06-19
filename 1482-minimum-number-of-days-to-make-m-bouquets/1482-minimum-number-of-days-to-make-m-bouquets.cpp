class Solution{
public:
    
    int f(int mid, vector<int> arr, int m, int k){
        
        int n = arr.size();
        for(int i=0; i<n; i++){
            if(arr[i] <= mid) arr[i] = 1;
            else arr[i] = 0;
        }
        
        int count = 0;
        int i = 0;
        
        while(i < n){
            
            if(arr[i] == 1){
                
                int cnt = 0;
                while(i<n and arr[i] == 1){
                    cnt++;
                    i++;
                }
                count += cnt/k;
            
            }else i++;
        }
        return count >= m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();
        if((long long)m*k > n) return -1;
        
        int s = 0;
        int e = 1e9;
        int ans = 0;
        
        while(s <= e){
            
            int mid = (s+e)/2;
            if(f(mid, bloomDay, m, k)){
                
                ans = mid;
                e = mid-1;
            
            }else s = mid+1;
        }
        return ans;
    }
};