class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        set<string> st;
        for(auto &i: arr1){
            
            string str = to_string(i);
            string s = "";
            for(auto &k: str){
                s += k;
                st.insert(s);
            }
        }
        int ans = 0;
        for(auto &i: arr2){
            
            string str = to_string(i);
            string s = "";
            for(auto &k: str){
                s += k;
                if(st.count(s)) ans = max(ans, (int)s.size());
            }
        }
        return ans;
        
    }
};