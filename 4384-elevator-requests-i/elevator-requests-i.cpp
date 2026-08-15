class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        
        int sum = 0;
        int prev = 0;
        for(auto &i: requests){
            sum += abs(prev - i);
            prev = i;
        }
        return sum;
    }
};