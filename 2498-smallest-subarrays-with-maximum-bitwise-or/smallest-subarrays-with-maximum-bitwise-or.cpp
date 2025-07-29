class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> bitArr(n);
        for(int i=0; i<n; i++){
            bitset<65> bits(nums[i]);
            vector<int> temp;
            for(int j=0; j<65; j++){
                temp.push_back(bits[j]);
            }
            bitArr[i] = temp;
        }

        vector<vector<int>> maxBitDistance(n, vector<int> (65, 0));
        for(int k=64; k>=0; k--){
            int lastPos = -1;
            for(int i=n-1; i>=0; i--){
                if(bitArr[i][k] == 1){
                    lastPos = i;
                }
                maxBitDistance[i][k] = lastPos;
            }
        }
        int maxOr = 0;
        vector<int> ans(n, 0);
        for(int i=n-1; i>=0; i--){
            maxOr |= nums[i];
            bitset<65> bits(maxOr);
            int maxDis = 0;
            for(int k=0; k<65; k++){
                if(bits[k] == 1){
                    maxDis = max(maxDis, maxBitDistance[i][k]);
                }
            }
            ans[i] = max(maxDis-i+1, 1);
        }
        return ans;
    }
};