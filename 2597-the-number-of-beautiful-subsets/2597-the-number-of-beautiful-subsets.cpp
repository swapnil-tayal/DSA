class Solution {
public:
    
    int check(vector<int> &arr, int k){
        
        int n = arr.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(abs(arr[i]-arr[j]) == k) return 0;
            }
        }
        return 1;
    }
    
    int f(int i, vector<int> &nums, vector<int> &arr, int k){
        
        if(i == nums.size()){
            return check(arr, k);
        }
        
        arr.push_back(nums[i]);
        int pick = f(i+1, nums, arr, k);
        arr.pop_back();
        int npick = f(i+1, nums, arr, k);
        return pick + npick;
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        
        vector<int> arr;
        return f(0, nums, arr, k)-1;
    }
};