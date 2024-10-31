class Solution {
public:
    
    long long f(int rb, int fac, int limit, vector<int> &robot, vector<vector<int>> &factory, vector<vector<vector<long long>>> &dp){
        
        if(rb == robot.size()) return 0;
        if(fac == factory.size()) return 1e16;
        
        if(dp[rb][fac][limit] != -1) return dp[rb][fac][limit];
        
        long long newLimit = (fac+1 == factory.size()) ? 0 : factory[fac+1][1];
        long long ans = 1e16;
        
        if(limit-1 >= 0){
        
            // cout<<rb<<' '<<fac<<' '<<limit<<'\n';
            // int pickAndNext = abs(robot[rb] - factory[fac][0]) + f(rb+1, fac+1, newLimit, robot, factory);
            long long pickAnsCurr = abs(factory[fac][0] - robot[rb]) + f(rb+1, fac, limit-1, robot, factory, dp);
            long long next = f(rb, fac+1, newLimit, robot, factory, dp);
            ans = min({pickAnsCurr, next});
            
        }else{
            
            // cout<<newLimit<<'\n';
            long long next = f(rb, fac+1, newLimit, robot, factory, dp);
            ans = next;
        }
        return dp[rb][fac][limit] = ans;
    }
    
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        vector<vector<vector<long long>>> dp(101, vector<vector<long long>>(101, vector<long long>(101, -1)));
        
        return f(0, 0, factory[0][1], robot, factory, dp);
    }
};