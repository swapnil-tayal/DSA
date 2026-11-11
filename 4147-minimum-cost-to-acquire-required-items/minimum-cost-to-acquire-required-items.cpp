class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        long long ans = 0;
        if(cost1 + cost2 < costBoth){
            ans = (need1 * 1ll * cost1) + (need2 * 1ll * cost2);
            return ans;
        
        }else{

            long long mini = min(need1, need2);
            ans = mini * 1ll * costBoth;

            need1 -= mini;
            need2 -= mini;

            if(need1 > 0){
                if(cost1 < costBoth) ans += cost1 * 1ll * need1;
                else ans += costBoth * 1ll * need1;
            }else if(need2 > 0){
                if(cost2 < costBoth) ans += cost2 * 1ll * need2;
                else ans += costBoth * 1ll * need2;
            }
        }
        return ans;
    }
};