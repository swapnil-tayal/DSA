class Solution {
public:
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int cnt = 0;
        
        for(int k=0; k<n; k++){
            
            vector<int> arr(m, 0);
            
            for(int i=k; i<n; i++){
                
                unordered_map<int,int> mp;
                mp[0] = 1;
                int sum = 0;
                
                for(int j=0; j<m; j++){
                    arr[j] += matrix[i][j];
                    sum += arr[j];
                    if(mp.find(sum-target) != mp.end()){
                        cnt += mp[sum-target];
                    }
                    mp[sum]++;
                }
            }
        }
        return cnt;
        return 0;   
    }
};