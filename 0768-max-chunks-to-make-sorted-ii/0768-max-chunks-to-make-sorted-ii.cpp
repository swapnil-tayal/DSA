class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> a(arr.begin(), arr.end());
        sort(a.begin(), a.end());
    
        unordered_map<int, set<int>> mp;
        for(int i=0; i<n; i++){
            mp[arr[i]].insert(i);
        }
        
        int maxInd = -1;
        int cnt = 0;
        for(int i=0; i<n; i++){
            
            if(i > maxInd) cnt++;
            
            int num = a[i];
            int ind = *mp[num].begin();
            mp[num].erase(ind);
            
            if(ind > maxInd) maxInd = ind;
            else{
                // fuck off
            }
        }
        return cnt;
    }
};