class Solution {
public:
    
    void f(vector<int> &bit, int num, int sps){
        for(int i=0; i<32; i++){
            if(sps) bit[i] += (num % 2);
            else bit[i] -= (num % 2);
            num /= 2;
        }
    }
    int check(vector<int> &bit){
        
        int num = 0;
        for(int i=0; i<32; i++){
            num += bit[i] ? (1 << i) : 0;
        }
        return num;
    }
    
    int f(int mid, vector<int> &nums, int k){
        
        int n = nums.size();
        int i = 0;
        int j = 0;
        
        int orr = 0;
        vector<int> bit(32, 0);
        
        while(j < n){
            
            f(bit, nums[j], 1);
            if(j-i+1 < mid) j++;
            else{
                if(check(bit) >= k){
                    return 1;
                }
                f(bit, nums[i], 0);
                i++;
                j++;
            }
        }
        return 0;
    }
    
    int minimumSubarrayLength(vector<int>& nums, int k) {
        
        int n = nums.size();
        int s = 1;
        int e = n;
        int ans = -1;
        
        while(s <= e){
            
            int mid = (s+e)/2;
            if(f(mid, nums, k)){
                
                ans = mid;
                e = mid-1;
                
            }else s = mid+1;
        }
        return ans;
    }
};