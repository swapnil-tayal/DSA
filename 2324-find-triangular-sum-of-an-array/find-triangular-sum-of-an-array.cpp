class Solution {
public:
    
    int triangularSum(vector<int>& prev) {
        
        int n = prev.size();
        if(n == 1){
            return prev[0];
        }
        
        for(int i=1; i<n; i++){
            
            vector<int> curr(n-i, 0);
            for(int j=0; j<n-i; j++){
                
                curr[j] = (prev[j] + prev[j+1]) % 10;
            }
            
            if(n-i == 1){
                return (curr[0])%10;
            } 
            
            prev = curr;
        }
        
        return -1;
    }
};