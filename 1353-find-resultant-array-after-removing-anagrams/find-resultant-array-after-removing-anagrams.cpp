class Solution {
public:

    int f(string &s1, string &s2){
        map<char,int> mp;
        for(auto &i: s1) mp[i]++;
        for(auto &i: s2) mp[i]--;
        for(auto &i: mp){
            if(i.second != 0) return 0;
        }return 1;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        
        stack<string> st;
        for(auto &i: words){
            if(st.size() == 0) st.push(i);
            if(f(st.top(), i)){}
            else st.push(i);
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