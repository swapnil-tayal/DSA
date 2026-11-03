class Solution {
public:

    int f(vector<int> &a){

        int n = a.size();
        int negs = 0;
        for(auto &i: a) negs += (i<0);

        if(negs % 2 == 0) return accumulate(a.begin(), a.end(), 1, std::multiplies<int>());
        else{

            int ans = -1e9;
            vector<int> pre(n);
            vector<int> suf(n);
            pre[0] = a[0];
            suf[n-1] = a[n-1];

            for(int i=1; i<n; i++) pre[i] = pre[i-1] * a[i];
            for(int i=n-2; i>=0; i--) suf[i] = suf[i+1] * a[i];

            for(int i=0; i<n; i++){
                if(a[i] > 0) continue;
                int s1 = (i-1 >= 0 ? pre[i-1] : -1e9);
                int s2 = (i+1 < n ? suf[i+1] : -1e9);
                ans = max({s1, s2, a[i], ans});
            }
            return ans;
        }
    }

    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> a;
        vector<int> temp;

        int ans = -1e9;
        int i = 0;
        
        while(i < n){
            if(nums[i] == 0){
                ans = 0;
                if(temp.size()) a.push_back(temp);
                temp = vector<int>();
            }else temp.push_back(nums[i]);
            i++;
        }
        if(temp.size()) a.push_back(temp);

        for(auto &i: a){
            for(auto k: i) cout<<k<<' ';
            cout<<'\n';
            ans = max(ans, f(i));
        }
        return ans;
    }
};