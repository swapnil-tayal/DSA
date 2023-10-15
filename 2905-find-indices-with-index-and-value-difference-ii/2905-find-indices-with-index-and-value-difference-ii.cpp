class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int id, int vd) {
        
        int n = nums.size();
        vector<vector<int>> arr(n, vector<int>(4));
        arr[0][0] = nums[0];
        arr[0][1] = 0;
        arr[0][2] = nums[0];
        arr[0][3] = 0;
        
        for(int i=1; i<n; i++){
            
            arr[i] = arr[i-1];
            
            if(arr[i-1][0] < nums[i]){
                
                arr[i][0] = nums[i];
                arr[i][1] = i;
            
            }if(arr[i-1][2] > nums[i]){
                
                arr[i][2] = nums[i];
                arr[i][3] = i;
            }
        }
        // for(auto i: arr){
        //     for(auto j: i) cout<<j<<' ';
        //     cout<<'\n';
        // }
        
        for(int i=id; i<n; i++){
            
            int k = i-id;
            if(abs(arr[k][0] - nums[i]) >= vd) return {arr[k][1], i};
            if(abs(arr[k][2] - nums[i]) >= vd) return {arr[k][3], i};
        }
        
        return {-1, -1};
    }
};