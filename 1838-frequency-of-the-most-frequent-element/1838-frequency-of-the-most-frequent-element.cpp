class Solution {
public:
    
    int f(int mid, vector<int> &nums, int k){
        
        // cout<<mid<<' ';
        if(mid == 0) return 1;
        
        int n = nums.size();
        
        int i = 0;
        int j = 0;
        long long sm = 0;
        while(j < n){
            
            sm += nums[j];
            if(j-i+1 < mid) j++;
            else{
                
                long long req = (long long)nums[j]*(long long)mid;
                // if(mid == 1) cout<<req<<' '<<sm<<'\n';
                if(sm <= req and k >= req - sm) return 1;
                sm -= nums[i];
                i++;
                j++;
            }
        }
        return 0;
    }
    
    int maxFrequency(vector<int>& nums, int k) {
        
        int s = 0;
        int e = 1e5;
        int ans = 0;
        sort(nums.begin(), nums.end());
        
        while(s <= e){
            
            int mid = (s+e)/2;
            if(f(mid, nums, k)){
                
                ans = mid;
                s = mid+1;
            }else e = mid-1;
        }
        return ans;
    }
};