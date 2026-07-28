class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        int n = nums.size();
        if(n <= 2) return n;
        bitset<32> it(n);
        int x = 0;
        for(int i=0; i<32; i++){
            if(it[i] == 1){
                x = (i+1);
            }
        }
        return pow(2, x);
    }
};
// 1111