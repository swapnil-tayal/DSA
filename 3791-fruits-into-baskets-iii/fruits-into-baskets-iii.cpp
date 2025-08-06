class segTree{
    vector<int> segMIN;
public:
    segTree(int n){
        segMIN.resize((4*n)+1 ,0);
    }
//                      0        0       n-1      
    void buildMIN(int ind, int low, int high, vector<int> &arr){
        if(low == high){
            segMIN[ind] = arr[low];
            return;
        }
        int mid = (low+high)/2;
        buildMIN(ind*2 + 1, low, mid, arr);
        buildMIN(ind*2 + 2, mid+1, high, arr);
        segMIN[ind] = min(segMIN[2*ind+1], segMIN[2*ind+2]);
    }
//                     0        0       n-1      r      e
    int queryMIN(int ind, int low, int high, int l, int r){
        // no overlap
        if(r < low || high < l) return INT_MAX;
        // complete overlap
        if(low >= l and high <= r) return segMIN[ind];
        int mid = (low+high)/2;
        int left = queryMIN(2*ind + 1, low, mid, l, r);
        int right = queryMIN(2*ind + 2, mid+1, high, l, r);
        return min(left, right);
    }
    void updateMIN(int ind, int low, int high, int i, int val) {
        if (low == high) {
            segMIN[ind] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (i <= mid) updateMIN(2 * ind + 1, low, mid, i, val);
        else updateMIN(2 * ind + 2, mid + 1, high, i, val);
        segMIN[ind] = min(segMIN[2 * ind + 1], segMIN[2 * ind + 2]);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        
        vector<pair<int,int>> basketsPairs;
        vector<int> sortedBaskets;
        vector<int> ind;
        map<int,int> mp;
        for(int i=0; i<baskets.size(); i++){
            basketsPairs.push_back({ baskets[i], i });
            sortedBaskets.push_back(baskets[i]);
        }
        sort(sortedBaskets.begin(), sortedBaskets.end());
        sort(basketsPairs.begin(), basketsPairs.end());
        for(auto i: basketsPairs) ind.push_back(i.second);
        for(int i=0; i<ind.size(); i++) mp[ind[i]] = i;

        segTree* sT = new segTree(ind.size()); 
        sT->buildMIN(0, 0, ind.size()-1, ind);

        int ans = 0;
        for(auto &i: fruits){
            
            int k = lower_bound(sortedBaskets.begin(), sortedBaskets.end(), i) - sortedBaskets.begin();
            if(k == sortedBaskets.size()){
                ans++;
                continue;
            }
            int lowestIndex = sT->queryMIN(0, 0, ind.size()-1, k, ind.size()-1);
            // for(auto j: sortedBaskets) cout<<j<<' ';
            // cout<<'\n';
            // for(auto j: ind) cout<<j<<' ';
            // cout<<'\n';
            // cout<<i<<' '<<k<<' ';
            // cout<<lowestIndex<<' '<<mp[lowestIndex]<<'\n';
            if(lowestIndex == 1e9) ans++;
            else{
                ind[mp[lowestIndex]] = 1e9;
                sT->updateMIN(0, 0, ind.size()-1, mp[lowestIndex], 1e9);
            }
        }
        return ans;
    }
};