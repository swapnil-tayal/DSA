class Solution {
    vector<long long> pre;
public:

    void f(vector<int> &nums){

        int max = *max_element(nums.begin(), nums.end());
        vector<int> freq(max+1, 0);
        
        for(auto &i: nums) freq[i]++;

        vector<long long> cnt(max+1, 0);
        for(int d=1; d<=max; d++){
            for(int m=d; m<=max; m+=d){
                cnt[d] += freq[m];
            }
        }

        vector<long long> exact;
        exact.assign(max+1, 0);
        for(int d=max; d>=1; d--){
            exact[d] = cnt[d] * (cnt[d]-1) / 2;
            for(int m=d+d; m<=max; m+=d){
                exact[d] -= exact[m]; 
            }
        }

        // for(auto i: exact){
        //     cout<<i<<' ';
        // }cout<<'\n';

        pre.assign(max+1, 0);
        pre[0] = exact[0];
        for(int i=1; i<=max; i++){
            pre[i] = pre[i-1] + exact[i];
        }

        // for(auto i: pre){
        //     cout<<i<<' ';
        // }cout<<'\n';
    }

    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
         
        f(nums);
        vector<int> ans;
        for(auto &i: queries){
            int ind = upper_bound(pre.begin(), pre.end(), i) - pre.begin();
            ans.push_back(ind);
        }
        return ans;
    }
};