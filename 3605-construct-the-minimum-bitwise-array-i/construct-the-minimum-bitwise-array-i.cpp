class Solution {
public:
    int f(int x){

        for(int i=0; i<=1000; i++){
            if((i | (i+1)) == x){
                return i;
            }
        }
        return -1;
    }

    vector<int> minBitwiseArray(vector<int>& nums) {

        vector<int> ans;        
        for(auto &i: nums){
            ans.push_back(f(i));
        }
        return ans;
    }
};