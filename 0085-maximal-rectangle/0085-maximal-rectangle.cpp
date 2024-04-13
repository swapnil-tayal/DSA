class Solution {
public:
    
    int f(vector<int> &a){
        
        int n = a.size();
        vector<int> leftSmall(n, 0);
        vector<int> rightSmall(n, 0);
        
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() and a[st.top()] >= a[i]){
                st.pop();
            }
            if(st.empty()) leftSmall[i] = 0;
            else leftSmall[i] = st.top()+1;
            st.push(i);
        }
        
        while(st.size()) st.pop();
        
        for(int i=n-1; i>=0; i--){
            while(!st.empty() and a[st.top()] >= a[i]){
                st.pop();
            }
            if(st.empty()) rightSmall[i] = n-1;
            else rightSmall[i] = st.top()-1;
            st.push(i);
        }
        
        // for(auto i: leftSmall) cout<<i<<' ';
        // cout<<'\n';
        // for(auto i: rightSmall) cout<<i<<' ';
        // cout<<'\n';
        
        int ans = 0;
        for(int i=0; i<n; i++){
            
            ans = max(ans, (rightSmall[i]-leftSmall[i]+1) * a[i]);
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        
        vector<int> a(m, 0);
        for(int i=0; i<n; i++){
            
            for(int j=0; j<m; j++){
                
                if(matrix[i][j] == '1') a[j]++;
                else a[j] = 0;
            }
            // for(auto k: a) cout<<k<<' ';
            // cout<<'\n';
            ans = max(ans, f(a));
        }
        return ans;
    }
};