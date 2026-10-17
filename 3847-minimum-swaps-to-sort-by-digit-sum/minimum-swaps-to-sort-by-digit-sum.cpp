class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> a = nums;

        sort(a.begin(), a.end(), [](int a, int b){
            int x = a, y = b;
            int sa = 0, sb = 0;
            while(x > 0) {
                sa += x % 10;
                x /= 10;
            }
            while(y > 0) {
                sb += y % 10;
                y /= 10;
            }
            if(sa == sb) return a < b;
            return sa < sb;
        });

        map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[a[i]] = i;
        }
        map<int,int> mp2;
        for(int i=0; i<n; i++){
            mp2[i] = mp[nums[i]];
        }

        vector<bool> vis(n, false);
        int cnt = 0;
        for(int i = 0; i < n; i++){

            if(vis[i] || mp2[i] == i) continue;
            int start = i;
            int cycle = 0;
            while(!vis[start]){
                vis[start] = true;
                start = mp2[start];
                cycle++;
            }
            cnt += cycle - 1;
        }

        return cnt;
    }
};