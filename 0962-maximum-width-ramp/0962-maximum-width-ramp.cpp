// https://codeforces.com/problemset/problem/1473/D
// https://codeforces.com/problemset/problem/1472/E

class segTree{

    vector<int> segMAX;
    vector<int> segMIN;
public:
    segTree(int n){
        segMAX.resize((4*n)+1 ,0);
        segMIN.resize((4*n)+1 ,0);
    }   
    void buildMAX(int ind, int low, int high, vector<int> &arr){
        if(low == high){
            segMAX[ind] = arr[low];
            return;
        }
        int mid = (low+high)/2;
        buildMAX(ind*2 + 1, low, mid, arr);
        buildMAX(ind*2 + 2, mid+1, high, arr);
        segMAX[ind] = max(segMAX[2*ind+1], segMAX[2*ind+2]);
    }
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
    int queryMAX(int ind, int low, int high, int l, int r){
        
        // no overlap
        if(r < low || high < l) return INT_MIN;

        // complete overlap
        if(low >= l and high <= r) return segMAX[ind];

        int mid = (low+high)/2;
        int left = queryMAX(2*ind + 1, low, mid, l, r);
        int right = queryMAX(2*ind + 2, mid+1, high, l, r);
        return max(left, right);
    }
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
};

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        
        int n = nums.size();
        vector<pair<int,int>> a;
        for(int i=0; i<n; i++){
            a.push_back({ nums[i], i });
        }
        sort(a.begin(), a.end());
        
        vector<int> v1, v2;
        for(auto &i: a){
            v1.push_back(i.first);
            v2.push_back(i.second);
        }
        
        segTree* st = new segTree(n);
        st->buildMAX(0, 0, n-1, v2);
        
        int ans = 0;
        for(int i=0; i<n; i++){
            
            int ind = lower_bound(v1.begin(), v1.end(), nums[i]) - v1.begin();
            if(ind != n && v1[ind] == nums[i]){
                ind++;
            }
            
            int d = st->queryMAX(0, 0, n-1, ind, n-1);
            
            if(ind != n) ans = max(ans, d-i);
        }
        return ans;
    }
};