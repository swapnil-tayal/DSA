class Solution {
public:

    long long count(long long x, vector<int>& coins) {

        // {LCM, sign}
        vector<pair<long long, int>> v;

        for (auto &c : coins) {
            int n = v.size();

            // Single coin
            if (c <= x) v.push_back({c, 1});

            // Add current coin to all existing combinations
            for (int i = 0; i < n; i++) {

                long long l = v[i].first;
                long long g = gcd(l, (long long)c);

                // lcm = l / gcd(l,c) * c
                if (l > x / (c / g)) continue;
                long long newLcm = l / g * c;

                if (newLcm > x) continue;
                // Flip sign:
                // + -> -
                // - -> +
                v.push_back({newLcm, -v[i].second});
            }
        }

        long long ans = 0;
        for (auto [lcm, sign] : v) ans += sign * (x / lcm);
        return ans;
    }


    long long findKthSmallest(vector<int>& coins, int k) {

        long long s = 1;
        long long e = 1LL * k * (*min_element(coins.begin(), coins.end()));

        while (s < e) {

            long long mid = s + (e - s) / 2;
            if (count(mid, coins) >= k) e = mid;
            else s = mid + 1;
        }
        return s;
    }
};