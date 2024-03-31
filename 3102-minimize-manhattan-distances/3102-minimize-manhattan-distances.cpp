class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        
        int n = points.size();
        multiset<long long> plus, minus;
        for(auto i: points){
            plus.insert( i[0] + i[1] );
            minus.insert( i[0] - i[1] );
        }
        long long ans = 1e15;
        
        for(int i=0; i<n; i++){
            
            int sum = points[i][0] + points[i][1];
            int diff = points[i][0] - points[i][1];
            plus.erase(plus.find(sum));
            minus.erase(minus.find(diff));
        
            long long val = max(*plus.rbegin() - *plus.begin(), *minus.rbegin() - *minus.begin());
            ans = min(ans, val);
            plus.insert(sum);
            minus.insert(diff);
            
        }
        return ans;
    }
}; 