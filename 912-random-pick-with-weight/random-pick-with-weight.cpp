#include <random>

class Solution {
    std::mt19937 gen{std::random_device{}()};
    std::discrete_distribution<int> dist;

public:
    Solution(vector<int>& w) : dist(w.begin(), w.end()) { }
    
    int pickIndex() {
        return dist(gen);
    }
};