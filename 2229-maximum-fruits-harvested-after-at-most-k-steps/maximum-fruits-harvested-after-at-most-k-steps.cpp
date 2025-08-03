class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        
        int n = fruits.size();
        vector<int> pos, amount;
        for (auto &i : fruits) {
            pos.push_back(i[0]);
            amount.push_back(i[1]);
        }
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + amount[i];

        int ans = 0;
        int i = 0;
        int j = 0;

        while(j < n) {
            while (i <= j) {
                int l = pos[i];
                int r = pos[j];
                int dist = min(abs(startPos - l), abs(startPos - r)) + (r - l);
                if (dist <= k) break;
                i++;
            }
            if (i <= j) {
                int total = prefix[j + 1] - prefix[i];
                ans = max(ans, total);
            }
            j++;
        }
        return ans;
    }
};
