class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for(auto i: nums) cnt += !(((int)to_string(i).length())%2);
        return cnt;
    }
};