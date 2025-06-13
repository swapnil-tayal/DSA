class Solution {
public:
    
    int f(int mid, vector<int> &nums, int p){
        
        int n = nums.size();
        for(int i=0; i<n-1; i++){
            if(nums[i+1]-nums[i] <= mid){
                p--;
                i++;
            }
        }
        return p <= 0;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        
        sort(nums.begin(), nums.end());
        int s = 0;
        int e = 1e9;
        int ans = 0;
        
        while(s <= e){
            
            int mid = (s+e)/2;
            if(f(mid, nums, p)){
                
                ans = mid;
                e = mid-1;
                
            }else s = mid+1;
        }
        return ans;
    }
};