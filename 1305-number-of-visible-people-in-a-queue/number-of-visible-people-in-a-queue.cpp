class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& a) {
        
        int n = a.size();
        stack<pair<int,int>> st;
        vector<int> ans;

        for(int i=n-1; i>=0; i--){

            int cnt = 0;
            int check = 0;
            while(st.size() and st.top().first < a[i]){
                // check = 1;
                cnt++;
                st.pop();
            }
            // cnt += check;
            if(st.size()){
                cnt++;
            }
            ans.push_back(cnt);
            st.push({ a[i], cnt });
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};