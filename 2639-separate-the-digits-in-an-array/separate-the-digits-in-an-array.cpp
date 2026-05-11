class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        
        vector<int> a;
        int n = nums.size();
        for(int i=0; i<n; i++){
            
            int x = nums[i];
            vector<int> c;
            while(x > 0){
                c.push_back(x%10);
                x = x/10;
            }
            reverse(c.begin(), c.end());
            for(auto &k: c){
                a.push_back(k);
            }
        }
        return a;
    }
};