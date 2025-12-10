class Solution {
public:

    int countPermutations(vector<int>& complexity) {

        int n = complexity.size();
        for(int i=1; i<n; i++){
            if(complexity[i] <= complexity[0]) return 0;
        }
        long long ans = 1;
        for(int i=1; i<n; i++){
            ans = (ans * i) % int(1e9+7);
        }
        return ans;
    }
};