class Solution {
public:
    int countPairs(vector<vector<int>>& a, int k) {
        
        map<vector<int>, int> mp;
        for(int i=0; i<a.size(); i++) mp[a[i]]++;
        int n = a.size();
        long long cnt = 0;
        
        for(int i=0; i<n; i++){
            
            int x1 = a[i][0];
            int y1 = a[i][1];
            
            for(int j=0; j<=k; j++){
                
                int x2 = (x1 ^ j);
                int y2 = (y1 ^ (k-j));
                
                if(mp.find({x2, y2}) != mp.end()){
                    cnt += mp[{x2, y2}];
                    if(x1 == x2 and y1 == y2) cnt--;
                }
            }
        }
        return cnt/2;
    }
};