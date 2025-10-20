class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        
        int cnt = 0;
        for(auto &i: operations){
            if(i == "++X" || i == "X++") cnt++;
            else cnt--;
        }
        return cnt;
    }
};