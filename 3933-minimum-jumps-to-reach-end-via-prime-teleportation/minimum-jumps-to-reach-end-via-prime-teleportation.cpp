class Solution {
public:

    int LIMIT;
    vector<int> spf;

    void buildSPF() {
        spf.resize(LIMIT+1, 0);
        iota(spf.begin(), spf.end(), 0);
        for (int i = 2; (long long)i * i <= LIMIT; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= LIMIT; j += i)
                    if (spf[j] == j)
                        spf[j] = i;
            }
        }
    }

    vector<int> primeFactors(int n) {
        vector<int> factors;
        while (n > 1) {
            int p = spf[n];
            while (n % p == 0) {
                factors.push_back(p);
                n /= p;
            }
        }
        return factors;
    }

    int minJumps(vector<int>& nums) {
        
        LIMIT = *max_element(nums.begin(), nums.end());
        buildSPF();
        int n = nums.size();

        unordered_map<int, vector<int>> factMap;
        for(int i=0; i<n; i++) {
            vector<int> factors = primeFactors(nums[i]);
            for(auto &k: factors) {
                factMap[k].push_back(i);
            }
        }

        vector<int> vis(n, 0);
        queue<int> q;
        q.push(0);
        int cnt = 0;

        while(!q.empty()){

            int sz = q.size();
            while(sz--){
                
                int x = q.front();
                q.pop();
                
                if(x == n-1) return cnt;
                vis[x] = 1;
                
                if(x+1 < n and !vis[x+1]){
                    q.push(x+1);
                }
                if(x-1 >= 0 and !vis[x-1]){
                    q.push(x-1);
                }
                for(auto &k: factMap[nums[x]]){
                    if(!vis[k]) q.push(k);
                }
                if(factMap[nums[x]].size() > 0){
                    factMap[nums[x]].clear();
                }
            }
            cnt++;
        }
        return -1;
    }
};