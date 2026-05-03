class segTree{

    vector<int> seg;
public:
    segTree(int n){
        seg.resize((4*n)+1 ,0);
    }
    void build(int ind, int low, int high, vector<int> &arr){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }
        int mid = (low+high)/2;
        build(ind*2 + 1, low, mid, arr);
        build(ind*2 + 2, mid+1, high, arr);
        seg[ind] = max(seg[2*ind+1], seg[2*ind+2]);
    }

    int query(int ind, int low, int high, int l, int r){
        if(r < low || high < l) return INT_MIN;
        if(low >= l and high <= r) return seg[ind];
        int mid = (low+high)/2;
        int left = query(2*ind + 1, low, mid, l, r);
        int right = query(2*ind + 2, mid+1, high, l, r);
        return max(left, right);
    }

    void update(int ind, int low, int high, int i, int val){
        if(low == high){
            seg[ind] = val;
            return;
        }
        int mid = (low + high)/2;
        if(i <= mid) update(2*ind+1, low, mid, i, val);
        else update(2*ind+2, mid+1, high, i, val);
        seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
    }
};

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {

        sort(properties.begin(), properties.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        int n = properties.size();

        vector<int> a, d;
        map<int,int> mp;
        int ind = 0;
        for(auto &i: properties){
            a.push_back(i[0]);
            d.push_back(i[1]);
            mp[i[0]] = ind++;
        }

        for(auto i: a) cout<<i<<' ';
        cout<<'\n';
        for(auto i: d) cout<<i<<' ';
        cout<<'\n';

        segTree *seg = new segTree(n);
        seg->build(0, 0, n-1, d);
        int cnt = 0;

        for(int i=0; i<n-1; i++){
            if(seg->query(0, 0, n-1, mp[a[i]]+1, n-1) > d[i]){
                cnt++;
            }
        }
        return cnt;
    }
};