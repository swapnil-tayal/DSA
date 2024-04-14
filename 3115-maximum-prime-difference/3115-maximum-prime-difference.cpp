class Solution {
public:
    
    bool isPrime(int n){
        // Corner case
        if (n <= 1)
            return false;

        // Check from 2 to n-1
        for (int i = 2; i <= n / 2; i++)
            if (n % i == 0)
                return false;

        return true;
    }
    
    int maximumPrimeDifference(vector<int>& nums) {
        
        int n = nums.size();
        int ind1 = -1;
        int ind2 = -1;
        
        for(int i=0; i<n; i++){
            if(isPrime(nums[i])){
                if(ind1 == -1) ind1 = i;
                ind2 = i;
            }
        }
        return ind2-ind1;
    }
};