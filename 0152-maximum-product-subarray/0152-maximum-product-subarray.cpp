class Solution {
public:
    
    int f(vector<int> &arr){
        
        int n = arr.size();
        int neg = 0;
        for(auto &i: arr) neg += (i<0);
        
        if(neg%2 == 0){
            int ans = 1;
            for(auto &i: arr) ans *= i;
            return ans;
        
        }else{
            
            vector<int> pre(n), suf(n);
            pre[0] = arr[0];
            suf[n-1] = arr[n-1];
            
            for(int i=1; i<n; i++) pre[i] = pre[i-1]*arr[i];
            for(int i=n-2; i>=0; i--) suf[i] = suf[i+1]*arr[i];
            
            int ans = 0;
                
            if(n == 1) ans = arr[0];
            
            for(int i=0; i<n; i++){
                if(arr[i] < 0){
                    if(i-1 >= 0) ans = max(pre[i-1], ans);
                    if(i+1 < n) ans = max(suf[i+1], ans);
                }
            }
            return ans;
        }
    }
    
    int maxProduct(vector<int>& nums) {
        
        vector<vector<int>> arr;
        int i = 0;
        int n = nums.size();
        int ans = -1e9;
        
        while(i < n){
            if(nums[i] == 0){
                ans = 0;
                i++;
            }
            else{
                vector<int> temp;
                while(i<n and nums[i] != 0){
                    temp.push_back(nums[i]);
                    i++;
                }arr.push_back(temp);
            }
        }
        for(auto &i: arr){
            ans = max(ans, f(i));
        }
        return ans;
    }
};