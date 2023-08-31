class Solution {
public:
    
    
    int minTaps(int n, vector<int>& ranges) {
        
        vector<vector<int>> a;
        
        for(int i=0; i<n+1; i++){  
            // if(ranges[i] == 0) continue;
            a.push_back({max(0, i-ranges[i]), i+ranges[i]});
        }
        sort(a.begin(), a.end());
        int curr = 0;
        int far = 0;
        int cnt = 1;
        
        // for(auto i: a) cout<<i[0]<<' '<<i[1]<<'\n';
        
        for(int i=0; i<=n; i++){
            
            if(a[i][0] <= curr) far = max(far, a[i][1]);
            else{
                
                if(far >= n) break;
                if(far < curr) return -1;
                curr = far;
                far = a[i][1]-1;
                cnt++;
            }
            if(far >= n) break;
        }
        if(far < n) return -1;
        return cnt;
        
    }
};