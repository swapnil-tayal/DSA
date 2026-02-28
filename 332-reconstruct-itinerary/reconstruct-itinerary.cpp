class Solution {
    map<string, priority_queue<string, vector<string>, greater<>>> mp;
    vector<string> ans;
public:

    void f(string src){

        while(mp[src].size()){
            string str = mp[src].top();
            mp[src].pop();
            f(str);
        }
        ans.push_back(src);
    
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        int n = tickets.size();
        for(auto &i: tickets){
            mp[i[0]].push(i[1]);
        }
        // stack<string> st;
        // st.push("JFK");

        // while(!st.empty()){

        //     string str = st.top();
        //     if(mp[str].size() == 0){
        //         ans.push_back(str);
        //         st.pop();
        //     }else{
        //         st.push(mp[str].top());
        //         mp[str].pop();
        //     }
        // }
        f("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};