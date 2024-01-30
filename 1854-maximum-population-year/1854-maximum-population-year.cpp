class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        
        vector<int> pre(101, 0);
        int n = logs.size();
        
        for(int i=0; i<n; i++){
            
            int str = logs[i][0] - 1950;
            int end = logs[i][1] - 1950;
            
            pre[str]++;
            pre[end]--;
        }
        for(int i=1; i<=100; i++){
            pre[i] += pre[i-1];
        }
        int max = *max_element(pre.begin(), pre.end());
        for(int i=0; i<=100; i++){
            if(pre[i] == max){
                return i+1950;
            }
        }
        return -1;
    }
};