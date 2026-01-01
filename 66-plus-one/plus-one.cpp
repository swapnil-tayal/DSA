class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n = digits.size();
        int carry = 0;
        for(int i=n-1; i>=0; i--){

            int val = digits[i] + carry + (i == n-1 ? 1 : 0);
            digits[i] = val % 10;
            carry = val / 10;

        }
        if(carry > 0) digits.insert(digits.begin(), carry);
        return digits;
    }
};