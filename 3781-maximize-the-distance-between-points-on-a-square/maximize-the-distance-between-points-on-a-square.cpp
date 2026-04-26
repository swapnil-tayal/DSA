class Solution {
public:

    int getDis(vector<int> &a, vector<int> &b){
        return abs(a[0]-b[0]) + abs(a[1]-b[1]);
    }

    int f(int mid, int side, vector<vector<int>> &points, int k){
        
        int n = points.size();
        vector<int> nxt(n, 0);
        int j = 0;

        for(int i=0; i<n; i++){

            if(j <= i) j = i+1;
            while(j < i+n && getDis(points[i], points[j % n]) < mid){
                j++;
            }
            if(j >= i+n) nxt[i] = i+n;
            else nxt[i] = j;
        }

        for(int start=0; start<n; start++){

            int curr = start;
            int flag = true;
            for(int step=0; step<k-1; step++){

                int nx = nxt[curr % n];
                if(nx <= curr) nx += n;
                if(nx >= start+n){
                    flag = false;
                    break;
                }
                curr = nx;
            }
            if(flag){
                if(getDis(points[start], points[curr % n]) >= mid){
                    return true;
                }
            }
        }
        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        
        int n = points.size();
        long long s = 0;
        long long e = 2 * side;
        int ans = -1;

        auto perimeterPos = [&](vector<int>& p) -> long long {
            int x = p[0], y = p[1];
            if (y == 0)    return x;
            if (x == side) return side + y;
            if (y == side) return 3LL * side - x;
            return 4LL * side - y;
        };
        sort(points.begin(), points.end(), [&](auto& a, auto& b){
            return perimeterPos(a) < perimeterPos(b);
        });

        while(s <= e){

            long long mid = (s+e)/2;
            if(f(mid, side, points, k)){

                ans = mid;
                s = mid+1;

            } else e = mid-1;
        }
        return ans;
    }
};