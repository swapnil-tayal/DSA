class Solution {
public:
    
    int subarraySum(vector<int>& nums, int k) {
        
        map<int,int> mp;
        int n = nums.size();
        int sum = 0;
        mp[0] = 1;
        int cnt = 0;
        
        for(int i=0; i<n; i++){
            
            sum += nums[i];
            if(mp.find(sum - k) != mp.end()){
                cnt += mp[sum-k];
            }
            mp[sum]++;
        }
        return cnt;
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int cnt = 0;
        
        for(int k=0; k<n; k++){
            
            vector<int> arr(m, 0);
            
            for(int i=k; i<n; i++){
                for(int j=0; j<m; j++){
                    arr[j] += matrix[i][j];
                }
                cnt += subarraySum(arr, target);
            }
        }
        return cnt;
        return 0;   
    }
};