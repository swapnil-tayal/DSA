class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        
        int n = nums.size();
        vector<int> a(n);
        
        int k = pow(2, maximumBit)-1;
        
        int xxor = 0;
        for(int i=0; i<n; i++){
            xxor ^= nums[i];
            a[n-i-1] = (xxor ^ k);
        }
        return a;
    }
};