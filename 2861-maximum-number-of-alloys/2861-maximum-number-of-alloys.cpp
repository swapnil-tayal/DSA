#define ll long long
class Solution {
public:
    
    int f(int mid, vector<vector<int>> &comp, vector<int> &stock, vector<int> &cost, int &budget){
        
        ll k = comp.size();
        ll n = cost.size();
        
        for(int i=0; i<k; i++){
            
            ll cnt = 0;
            for(int j=0; j<n; j++){
                
                ll req = (ll)comp[i][j] * (ll)mid;
                if(stock[j] >= req) continue;
                else cnt += (ll)(req - stock[j]) * (ll)cost[j];
            }
            if(cnt <= budget) return 1;
        }
        return 0;
    }
    
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& comp, vector<int>& stock, vector<int>& cost) {
        
        int s = 0;
        int e = 1e9;
        int ans = 0;
        
        while(s <= e){
            
            int mid = (s + e)/2;
            if(f(mid, comp, stock, cost, budget)){
                
                s = mid+1;
                ans = mid;
            
            }else e = mid-1;
        }
        return ans;
    }
};