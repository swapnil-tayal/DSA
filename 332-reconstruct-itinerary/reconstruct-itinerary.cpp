class Solution {
public:

    // void f()

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        int n = tickets.size();
        map<string, priority_queue<string, vector<string>, greater<>>> mp;
        for(auto &i: tickets){
            mp[i[0]].push(i[1]);
        }
        stack<string> st;
        vector<string> ans;
        st.push("JFK");

        while(!st.empty()){

            string str = st.top();
            if(mp[str].size() == 0){
                ans.push_back(str);
                st.pop();
            }else{
                st.push(mp[str].top());
                mp[str].pop();
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};