class Solution {
public:
    
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return;
        int i = n-1;
        int val = -1;
        
        while(i > 0){
            if(nums[i] > nums[i-1]){
                val = i-1;
                break;
            }i--;
        }
        if(val == -1){
            sort(nums.begin(), nums.end());
            return;
        }
        
        int val2 = i;
        int ac = n;
        for(int k=i; k<n; k++){
            if(nums[k] > nums[val]){
                if(ac > nums[k] and nums[val] < nums[k]){
                    ac = nums[k];
                    val2 = k;
                }
            }
        }
        swap(nums[val], nums[val2]);
        sort(nums.begin()+val+1, nums.end());
    }
    
    string getPermutation(int n, int k) {
        
        vector<int> num;
        for(int i=1; i<=n; i++) num.push_back(i);
        k--;
        while(k--){
            nextPermutation(num);
        }
        string str;
        for(auto &i: num){
            str += to_string(i);
        }
        return str;
    }
};