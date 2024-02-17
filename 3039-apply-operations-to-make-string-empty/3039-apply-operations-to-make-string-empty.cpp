class Solution {
public:
    string lastNonEmptyString(string s) {
        
        int n = s.size();
        map<char, int> mp;
        for(auto i: s) mp[i]++;
        
        priority_queue<pair<int,char>> pq;
        for(auto i: mp){
            pq.push({ i.second, i.first });
        }
        int minFreq = pq.top().first;
        set<int> st;
        // cout<<minFreq<<' ';
        while(!pq.empty() and pq.top().first == minFreq){
            st.insert(pq.top().second);
            pq.pop();
        }
        // cout<<st.size()<<'\n';
        string ans;
        for(int i=n-1; i>=0; i--){
            if(st.count(s[i])){
                ans += s[i];
                st.erase(s[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};