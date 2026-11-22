class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        unordered_map<long long, set<int>> mp;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i=0; i<n; i++){
            mp[nums[i]].insert(i);
        }
        set<vector<int>> ans;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){

                long long sum = nums[i] + nums[j];
                int s = j+1;
                int e = n-1;

                while(s < e){

                    if(sum + nums[s] + nums[e] < target) s++;
                    else if(sum + nums[s] + nums[e] > target) e--;
                    else{
                        ans.insert({ nums[i], nums[j], nums[s], nums[e] });
                        s++;
                        e--;
                    }
                }
            }
        }
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};