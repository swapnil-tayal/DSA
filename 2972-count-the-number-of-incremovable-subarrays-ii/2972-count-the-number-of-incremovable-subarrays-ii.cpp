class Solution {
public:
    
    long long countValid(vector<int> &str, vector<int> &end){
        
        int n = str.size();
        int m = end.size();
        long long ans = 0;
        
        for(int i=0; i<n; i++){
            
            int ind = lower_bound(end.begin(), end.end(), str[i]+1) - end.begin();
            ans += m-ind;
        }
        return ans + m + n;
    }
    
    long long incremovableSubarrayCount(vector<int>& nums) {
        
        int n = nums.size();
        
        int ind1 = 0;
        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1]) ind1 = i;
            else break;
        }
        if(ind1 == n-1) return n*(n+1)/2;
        int ind2 = n-1;
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]) ind2 = i;
            else break;
        }
        vector<int> str, end;
        // for(int i=0; i<=ind1; i++){
        //     str.push_back(nums[i]);
        // }
        
        for(int i=ind2; i<n; i++){
            end.push_back(nums[i]);
        }
        
        long long ans = 0;
        for(int i=0; i<=ind1; i++){
            int ind = lower_bound(end.begin(), end.end(), nums[i]+1) - end.begin();
            ans += end.size() - ind;
        }
        return ans + ind1+1 + end.size() + 1;
        
    }
};