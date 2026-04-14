class Solution {
    vector<vector<vector<long long>>> dp;
    long long MAX = 1e12;
public:

    long long f(int rb, int fc, int limit, vector<int> &robot, vector<vector<int>> &factory){
        
        if(rb == robot.size()) return 0;
        if(fc == factory.size()) return MAX;

        if(dp[rb][fc][limit] != -1) return dp[rb][fc][limit]; 
        long long pick = MAX;
        int nextLimit = fc + 1 < factory.size() ? factory[fc+1][1] : 0;

        if(limit-1 >= 0){
            pick = abs(robot[rb] - factory[fc][0]) + f(rb+1, fc, limit-1, robot, factory);
        }
        long long npick = f(rb, fc+1, nextLimit, robot, factory);
        
        return dp[rb][fc][limit] = min(pick, npick);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        dp.resize(robot.size(), vector<vector<long long>>(factory.size(), vector<long long>(robot.size()+1, -1)));
        return f(0, 0, factory[0][1], robot, factory);

    }
};