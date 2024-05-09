// https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/discuss/489929/O(n)-time-O(1)-space.-In-depth-Explanation.

class Solution{
    int n;
    int S;
public:
    
    int adjSum(vector<int> &nums){
        int sum = 0;
        for(int i=0; i<n-1; i++){
            sum += abs(nums[i] - nums[i+1]);
        } 
        return sum;
    }
    
    int prefixSubarray(vector<int> &nums){
        int ans = -1e9;
        for(int i=0; i<n-1; i++){
            ans = max(ans, S - abs(nums[i] - nums[i+1]) + abs(nums[0] - nums[i+1]));
        }
        return ans;
    }
    int sufixSubarray(vector<int> &nums){
        int ans = -1e9;
        for(int i=1; i<n; i++){
            ans = max(ans, S - abs(nums[i] - nums[i-1]) + abs(nums[i-1] - nums[n-1]));
        }
        return ans;
    }
    int midArray(vector<int> &a){
        
        int ans = -1e9;
        int max1 = -1e9, _max1 = -1e9, max2 = -1e9, _max2 = -1e9;
        int max3 = -1e9, _max3 = -1e9, max4 = -1e9, _max4 = -1e9;
        
        for(int i=0; i<n; i++){
            
            if(i-1 >= 0) max1 = max(max1, -abs(a[i] - a[i-1]) - a[i] - a[i-1]);
            if(i+1 < n) _max1 = max(_max1, -abs(a[i] - a[i+1]) + a[i] + a[i+1]);
            
            if(i-1 >= 0) max2 = max(max2, -abs(a[i] - a[i-1]) + a[i] - a[i-1]);
            if(i+1 < n) _max2 = max(_max2, -abs(a[i] - a[i+1]) + a[i] - a[i+1]);
            
            if(i-1 >= 0) max3 = max(max3, -abs(a[i] - a[i-1]) - a[i] + a[i-1]);
            if(i+1 < n) _max3 = max(_max3, -abs(a[i] - a[i+1]) - a[i] + a[i+1]);
            
            if(i-1 >= 0) max4 = max(max4, -abs(a[i] - a[i-1]) + a[i] + a[i-1]);
            if(i+1 < n) _max4 = max(_max4, -abs(a[i] - a[i+1]) - a[i] - a[i+1]);
        }
        
        ans = max(ans, S + max1 + _max1);
        ans = max(ans, S + max2 + _max2);
        ans = max(ans, S + max3 + _max3);
        ans = max(ans, S + max4 + _max4);
        return ans;
    }
    
    int maxValueAfterReverse(vector<int>& nums) {
        
        this->n = nums.size();
        this->S = adjSum(nums);
        
        int ans = max({ prefixSubarray(nums), sufixSubarray(nums), midArray(nums) });
        return ans;
    }
};