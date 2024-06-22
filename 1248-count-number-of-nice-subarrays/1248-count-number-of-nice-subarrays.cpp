class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        vector<int> arr;
        arr.push_back(-1);
        for(int i=0; i<n; i++){
            if(nums[i]%2){
                arr.push_back(i);
            }
        }
        arr.push_back(n);
        
        int i = 1;
        int j = 1;
        n = arr.size()-1;
        
        int ans = 0;
        while(j < n){
            
            if(j-i+1 < k) j++;
            else{
                ans += (arr[i]-arr[i-1]) * (arr[j+1]-arr[j]);
                i++;
                j++;
            }
        }
        return ans;
    }
};