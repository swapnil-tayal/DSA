class Solution {
public:

    int f(string s1, string s2){
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        
        stack<string> st;
        for(auto &i: words){
            if(st.size() == 0) st.push(i);
            if(!f(st.top(), i)) st.push(i);
        }
        vector<string> ans;
        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};