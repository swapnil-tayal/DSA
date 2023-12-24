class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        
        h.insert(h.begin(), 1);
        v.insert(v.begin(), 1);
        h.push_back(m);
        v.push_back(n);
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());
        
        set<int> hsize;
        for(int i=0; i<h.size(); i++){
            for(int j=i+1; j<h.size(); j++){
                hsize.insert(h[j] - h[i]);
            }
        }
        long long ans = -1;
        for(int i=0; i<v.size(); i++){
            for(int j=i+1; j<v.size(); j++){
                
                long long x = v[j]-v[i];
                if(hsize.count(v[j]-v[i])){
                    
                    ans = max(ans, x*x);
                }
            }
        }
        return ans % (1000000007);
    }
};