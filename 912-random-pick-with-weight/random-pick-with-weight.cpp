#include <random>

class Solution {
    vector<int> a;
    int sum = 0;
public:
    Solution(vector<int>& w) { 
        for(auto &i: w){
            sum += i;
            a.push_back(sum);
        }
    }

    int pickIndex() {

        int random = rand() % sum;
        int ind = upper_bound(a.begin(), a.end(), random) - a.begin();
        return ind;
    }
};