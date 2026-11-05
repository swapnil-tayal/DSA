
class Solution {
    vector<long long> cost;
    vector<vector<long long>> dp;
    int n;
    const long long INF = (1LL << 62);

public:

    void medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> left, right;
        long long sumLeft = 0, sumRight = 0;

        cost.assign(n - k + 1, 0);

        auto balance = [&]() {
            if (left.size() > right.size() + 1) {
                int val = *left.rbegin();
                left.erase(prev(left.end()));
                right.insert(val);
                sumLeft -= val;
                sumRight += val;
            }
            else if (left.size() < right.size()) {
                int val = *right.begin();
                right.erase(right.begin());
                left.insert(val);
                sumRight -= val;
                sumLeft += val;
            }
        };

        auto add = [&](int val) {
            if (left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                sumLeft += val;
            }
            else {
                right.insert(val);
                sumRight += val;
            }
            balance();
        };

        auto remove = [&](int val) {
            auto it = left.find(val);

            if (it != left.end()) {
                left.erase(it);
                sumLeft -= val;
            }
            else {
                it = right.find(val);
                right.erase(it);
                sumRight -= val;
            }
            balance();
        };

        int i = 0;

        for (int j = 0; j < n; j++) {
            add(nums[j]);
            if (j - i + 1 == k) {
                long long median = *left.rbegin();
                cost[i] = median * (long long)left.size() - sumLeft + sumRight - median * (long long)right.size();
                remove(nums[i]);
                i++;
            }
        }
    }

    long long f(int i, int x, int k) {

        if (k == 0) return 0;
        if (i >= n || n - i < 1LL * x * k) return INF;
        if (dp[i][k] != -1) return dp[i][k];

        long long npick = f(i + 1, x, k);
        long long pick = INF;
        if (i + x <= n) {
            long long next = f(i + x, x, k - 1);
            if (next != INF) {
                pick = cost[i] + next;
            }
        }
        return dp[i][k] = min(pick, npick);
    }

    long long minOperations(vector<int>& nums, int x, int k) {

        n = nums.size();
        medianSlidingWindow(nums, x);
        dp.assign(n + 1, vector<long long>(k + 1, -1));
        return f(0, x, k);
    }
};
