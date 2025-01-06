class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        int n = boxes.size();
        vector<int> pre(n, 0), suf(n, 0);

        int cnt = 0;
        int s0s = 0;
        for(int i=0; i<n; i++){
            pre[i] = (cnt * (cnt+1))/2 + s0s;
            if(boxes[i] == '1') cnt++;
            else s0s += cnt; 
        }
        cnt = 0;
        s0s = 0;
        for(int i=n-1; i>=0; i--){
            suf[i] = (cnt * (cnt+1))/2 + s0s;
            if(boxes[i] == '1') cnt++;
            else s0s += cnt;
        }
        // for(auto i: pre) cout<<i<<' ';
        // cout<<'\n';
        // for(auto i: suf) cout<<i<<' ';
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++){
            ans[i] = pre[i] + suf[i];
        }
        return ans;
    }
};