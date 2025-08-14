class Solution {
public:
    string largestGoodInteger(string num) {
        
        int n = num.size();
        string ans = "";
        
        for(int i=0; i<=n-3; i++){
            if(num[i] == num[i+1] and num[i+1] == num[i+2]){
                string temp;
                temp += num[i];
                temp += num[i];
                temp += num[i];
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};