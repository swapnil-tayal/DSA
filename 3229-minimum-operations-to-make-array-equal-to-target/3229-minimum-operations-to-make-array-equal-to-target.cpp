class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        
        int n = nums.size();
        vector<int> a(n);
        
        for(int i=0; i<n; i++){
            a[i] = nums[i] - target[i];
        }
        
        int inc = 0;
        int dec = 0;
        long long ans = 0;
        
        for(int i=0; i<n; i++){
            
            if(a[i] > 0){
                
                if(a[i] > inc){
                    ans += a[i] - inc;
                }
                inc = a[i];
                dec = 0;
            
            }else if(a[i] < 0){
                
                if(a[i] < -dec){
                    ans += -dec - a[i];
                }
                dec = -a[i];
                inc = 0;
                
            }else{
                inc = 0;
                dec = 0;
            }
        }
        return ans;
    }
}; 