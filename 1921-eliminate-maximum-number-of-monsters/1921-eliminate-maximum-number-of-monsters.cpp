class Solution {
public:
    
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        
        int n = dist.size();
        vector<int> arr(n, 0);
        for(int i=0; i<n; i++){
            
            int x = dist[i];
            int y = speed[i];
            arr[i] = ((x-1)/y);
        }

        sort(arr.begin(), arr.end());
        
        for(int i=0; i<n; i++){
            if(arr[i] < i) return i;
        }
        return n;
    }
};