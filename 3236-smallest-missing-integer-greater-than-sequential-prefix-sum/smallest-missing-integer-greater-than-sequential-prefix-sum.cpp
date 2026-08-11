class Solution {
public:
    int missingInteger(vector<int>& nums) {
        
        int n = nums.size();
        set<int> st;
        for(auto i: nums) st.insert(i);
        int sum = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i] != nums[i-1]+1){
                break;
            } else sum += nums[i];
        }
        while(st.count(sum)){
            sum++;
        }
        return sum;
    }
};