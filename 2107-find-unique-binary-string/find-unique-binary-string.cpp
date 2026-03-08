class Solution {
    set<string> st;
    string ans = "";
public:

    void f(int i, int n, string str){

        if(i == n){
            if(!st.count(str)) ans = str;
            return;
        }
        if(ans != "") return;
        f(i+1, n, str + '0');
        f(i+1, n, str + '1');
    }

    string findDifferentBinaryString(vector<string>& nums) {
        
        for(auto &i: nums) st.insert(i);
        f(0, nums.size(), "");
        return ans;
    }
};