class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        vector<string> ans;
        int k = 1;
        
        int i = 0;
        while(k <= n and i<target.size()){
            
            if(target[i] != k){
                ans.push_back("Push");
                ans.push_back("Pop");
                
            }else{
                ans.push_back("Push");
                i++;
            }k++;
        }
        return ans;
    }
};