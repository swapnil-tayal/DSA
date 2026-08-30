class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        
        int n = nums.size();
        int indMX = max_element(nums.begin(), nums.end()) - nums.begin();
        int indMI = min_element(nums.begin(), nums.end()) - nums.begin();

        if(indMI > indMX) swap(indMX, indMI);

        int a1 = indMI + 1 + n - indMX;
        int a2 = indMX+1;
        int a3 = n - indMI;
        return min({a1, a2, a3});
    }
};