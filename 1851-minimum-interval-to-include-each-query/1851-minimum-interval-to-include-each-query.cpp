bool cmp(vector<int> &a1, vector<int> &a2){
    return a1[1]-a1[0] < a2[1]-a2[0];
}

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& itv, vector<int>& que) {
        
        int n = itv.size();
        int m = que.size();
        sort(itv.begin(), itv.end(), cmp);
    
        set<pair<int,int>> st;
        for(int i=0; i<m; i++){
            st.insert({ que[i], i });
        }
        vector<int> ans(m, -1);
        for(int i=0; i<n; i++){
            
            int s = itv[i][0];
            int e = itv[i][1];
            
            auto it = st.lower_bound({ s, 0 });
            while(it != st.end() && it->first <= e){
                
                auto itNext = next(it);
                ans[it->second] = e-s+1;
                st.erase(it);
                it = itNext;
            }
        }
        return ans;
    }
};