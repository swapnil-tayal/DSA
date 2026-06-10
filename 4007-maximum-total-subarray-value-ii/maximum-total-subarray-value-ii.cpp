class segTree{
    vector<int> segMAX;
    vector<int> segMIN;
    int n;
public:
    segTree(int n){
        this->n = n;
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

    int getDiff(int s, int e){
        return queryMAX(0, 0, n-1, s, e) - queryMIN(0, 0, n-1, s, e);
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        
        int n = nums.size();
        segTree* sgt = new segTree(n);
        sgt->buildMAX(0, 0, n-1, nums);
        sgt->buildMIN(0, 0, n-1, nums);

        priority_queue<vector<int>> pq;
        pq.push({ sgt->getDiff(0, n-1), 0, n-1 });
        set<pair<int,int>> st;
        st.insert({ 0, n-1 });
        long long ans = 0;
        
        while(k > 0){

            ans += pq.top()[0];
            int l = pq.top()[1];
            int e = pq.top()[2];
            pq.pop();
            k--;

            if(l+1 <= e && !st.count({ l+1, e })){
                pq.push({ sgt->getDiff(l+1, e), l+1, e });
                st.insert({ l+1, e });
            }
            if(e-1 >= l && !st.count({ l, e-1 })){
                pq.push({ sgt->getDiff(l, e-1), l, e-1 });
                st.insert({ l, e-1 });
            }
        }
        return ans;
    }
};