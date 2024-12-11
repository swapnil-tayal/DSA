class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> line(400001, 0);
        
        for(auto &i: nums){
            
            line[100000 + i - k]++;
            line[100000 + i + k + 1]--;

        }
        vector<int> sum(400001, -1);
        sum[0] = line[0];
        int ans = line[0];
        for(int i=1; i<400001; i++){
            sum[i] = sum[i-1] + line[i];
            ans = max(ans, sum[i]);
        }
        return ans;
    }
};