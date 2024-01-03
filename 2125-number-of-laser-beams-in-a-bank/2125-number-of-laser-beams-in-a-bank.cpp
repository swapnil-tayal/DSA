class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        vector<int> ans;
        for(auto &i: bank){
            int cnt = 0;
            for(auto &j: i) cnt += j=='1';
            if(cnt > 0) ans.push_back(cnt);
        }
        int res = 0;
        int n = ans.size();
        for(int i=1; i<n; i++){
            res += ans[i] * ans[i-1];
        }
        return res;
    }
};