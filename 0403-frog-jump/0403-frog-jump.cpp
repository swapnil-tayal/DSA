#define all(x) x.begin(), x.end()

class Solution {
public:
    
    int f(int i, int prev, vector<int> &a, vector<vector<int>> &dp){
        
        if(i == a.size()-1) return 1;
        if( dp[i][prev+1] != -1 ) return dp[i][prev+1]; 
        
        int diff = a[i];
        if(prev != -1) diff = a[i] - a[prev];
        
        int next = 0;
        int same = 0;
        int less = 0;
        
        // cout<<prev<<' '<<i<<' '<<diff<<'\n';
        
        int ind = lower_bound(all(a), a[i]+diff+1) - a.begin();
        if(ind != a.size() and a[ind] == a[i] + diff + 1){
            next = f(ind, i, a, dp);
        }
        
        if(diff > 1){
            ind = lower_bound(all(a), a[i]+diff-1) - a.begin();
            if(ind != a.size() and a[ind] == a[i] + diff - 1){
                less = f(ind, i, a, dp);
            }
        }
        if(diff > 0){
            ind = lower_bound(all(a), a[i]+diff) - a.begin();
            if(ind != a.size() and a[ind] == a[i] + diff){
                same = f(ind, i, a, dp);
            }
        }        
        return dp[i][prev+1] = same || next || less;
    }
    
    bool canCross(vector<int>& stones) {
        
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(0, -1, stones, dp);
    }
};