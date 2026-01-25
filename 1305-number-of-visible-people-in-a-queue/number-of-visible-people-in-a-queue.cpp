class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& a) {
        
        int n = a.size();
        stack<int> st;
        vector<int> ans;

        for(int i=n-1; i>=0; i--){
            int cnt = 0;
            while(st.size() and st.top() < a[i]){
                cnt++;
                st.pop();
            }
            if(st.size()) cnt++;
            ans.push_back(cnt);
            st.push(a[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};