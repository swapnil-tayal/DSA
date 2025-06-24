class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        
        int n = nums.size();
        vector<int> prev(n, -1);
        vector<int> nxt(n, -1);

        int idx = -1;
        for(int i=0; i<n; i++){
            if(nums[i] == key) idx = i;
            prev[i] = idx;
        }
        idx = -1;
        for(int i=n-1; i>=0; i--){
            if(nums[i] == key) idx = i;
            nxt[i] = idx;
        }
        // for(auto i: prev) cout<<i<<' ';
        // cout<<'\n';
        // for(auto i: nxt) cout<<i<<' ';
        vector<int> ans;
        for(int i=0; i<n; i++){
            int r = 1e9;
            if(prev[i] != -1) r = i - prev[i];
            if(nxt[i] != -1) r = min(r, nxt[i]-i);
            if(r <= k) ans.push_back(i);
        }
        return ans;
    }
};