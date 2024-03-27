class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& arr, int k) {
        
        int n = arr.size();
        int i=0;
        int j=0;
        int sum = 1;
        int cnt = 0;
        
        while(j < n){
            
            sum = sum * arr[j];
            
            if(sum >= k){
                while(sum >= k and i < j){
                    sum = sum / arr[i];
                    i++;
                }
            }
            if(sum < k){
                cnt += j-i+1;
            }
            j++;
        }
        return cnt;
    }
};