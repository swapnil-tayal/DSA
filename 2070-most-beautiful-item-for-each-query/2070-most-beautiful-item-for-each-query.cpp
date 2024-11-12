class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        
        int n = items.size();
        sort(items.begin(), items.end());
        
        // for(auto i: items){
        //     cout<<i[0]<<' '<<i[1]<<'\n';
        // }
        
        vector<int> price;
        for(auto i: items) price.push_back(i[0]);
        
        vector<int> maxi(n, 0);
        maxi[0] = items[0][1];
        for(int i=1; i<n; i++){
            maxi[i] = max(maxi[i-1], items[i][1]);
        }
        
        vector<int> ans(queries.size(), 0);
        for(int i=0; i<queries.size(); i++){
            
            int ind = upper_bound(price.begin(), price.end(), queries[i]) - price.begin();
            if(ind == n) ind--;
            if(price[ind] > queries[i]) ind--;
            if(ind >= 0){
                // cout<<ind<<' ';
                ans[i] = maxi[ind];
            }
        }
        return ans;
    }
};