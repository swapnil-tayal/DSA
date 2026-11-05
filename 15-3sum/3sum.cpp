class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> ans;

        for(int i=0; i<n; i++){

            vector<int> a;
            int s = i+1;
            int e = n-1;

            while(s < e){

                if(-nums[i] > nums[s] + nums[e]) s++;
                else if(-nums[i] < nums[s] + nums[e]) e--;
                else{
                    a.push_back(nums[i]);
                    a.push_back(nums[s]);
                    a.push_back(nums[e]);
                    ans.insert(a);
                    a = {};
                    s++;
                    e--;
                }
            }
        }
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};