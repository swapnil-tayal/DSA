class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        
        vector<int> a(n, 1);
        
        while(k--){
            
            vector<int> pre(n, 0);
            pre[0] = a[0];
            for(int i=1; i<n; i++){
                pre[i] = (pre[i-1] + a[i]) % 1000000007;
            }
            a = pre;
        }
        
        return a[n-1];
    }
};