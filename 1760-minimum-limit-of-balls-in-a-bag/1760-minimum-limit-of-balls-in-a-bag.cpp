class Solution {
public:
    
    int f(int mid, vector<int> &nums, int mo){
        
        int n = nums.size();
        int cnt = 0;
        for(auto &i: nums){
            
            if(i%mid == 0) cnt += (i/mid)-1;
            else{
                cnt += i/mid;
            }
        }
        return cnt <= mo;
    }
    
    int minimumSize(vector<int>& nums, int mo) {
        
        int s = 1;
        int e = 1e9;
        int ans = 0;
        
        while(s <= e){
            
            int mid = (s+e)/2;
            if(f(mid, nums, mo)){
                
                ans = mid;
                e = mid-1;
                
            }else s = mid+1;
        }
        return ans;
    }
};