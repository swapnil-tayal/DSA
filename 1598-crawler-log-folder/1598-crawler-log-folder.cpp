class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        int cnt = 0;
        for(auto i: logs){
            
            if(i == "../"){
                cnt = max(0, cnt-1);
            }else if(i == "./"){
                continue;
            }else{
                cnt++;
            }
        }
        return cnt;
    }
};