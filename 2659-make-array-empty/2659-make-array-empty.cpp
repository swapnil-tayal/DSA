class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int,int> orgInd;
        
        for(int i=0; i<n; i++){
            orgInd[nums[i]] = i;
        }
        sort(nums.begin(), nums.end());
        long long ans = n;
        int lastInd = -1;
        
        for(int i=0; i<n; i++){
            if(lastInd > orgInd[nums[i]]) ans += n-i;
            lastInd = orgInd[nums[i]];
        }
        return ans;
    }
};