class Solution {
public:

    vector<int> countsort(vector<int>& arr) {
        int n = arr.size();

        int maxval = 0;
        for (int i = 0; i < n; i++)
            maxval = max(maxval, arr[i]);
            
        // create and initialize cntArr array
        vector<int> cntArr(maxval + 1, 0);

        // count frequency of each element
        for (int i = 0; i < n; i++)
            cntArr[arr[i]]++;

        // compute prefix sum
        for (int i = 1; i <= maxval; i++)
            cntArr[i] += cntArr[i - 1];

        // build output array
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            ans[cntArr[arr[i]] - 1] = arr[i];
            cntArr[arr[i]]--;
        }

        return ans;
    }

    int maxIceCream(vector<int>& costs, int coins) {
        
        int n = costs.size();
        costs = countsort(costs);
        for (int i=0; i<n; ++i){
            if ((coins -= costs[i]) < 0){
                return i;
            }
        }
        return n;
    }
};