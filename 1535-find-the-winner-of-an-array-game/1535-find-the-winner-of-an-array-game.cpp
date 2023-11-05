class Solution {
public:
    
    vector<int> f(vector<int> &arr){
        
        stack<pair<int,int>> st;
        st.push({ arr[0], 0 });
        
        int n = arr.size();
        vector<int> res(n, -1);
        
        for(int i=0; i<n; i++){
            
            while(!st.empty() and st.top().first <= arr[i]){
                st.pop();
            }
            
            if(st.empty()) res[i] = -1;
            else res[i] = st.top().second;
            st.push({ arr[i], i });
        }
        return res;
    }
    vector<int> f2(vector<int> &arr){
        
        stack<pair<int,int>> st;
        int n = arr.size();
        
        st.push({ arr[n-1], n-1 });
        
        vector<int> res(n, -1);
        
        for(int i=n-1; i>=0; i--){
            
            while(!st.empty() and st.top().first <= arr[i]){
                st.pop();
            }
            
            if(st.empty()) res[i] = -1;
            else res[i] = st.top().second;
            st.push({ arr[i], i });
        }
        return res;
    }
    
    int getWinner(vector<int>& arr, int k) {
        
        int n = arr.size();
        vector<int> left = f(arr);
        vector<int> right = f2(arr);
        
        // for(auto i: left) cout<<i<<' ';
        // cout<<'\n';
        // for(auto i: right) cout<<i<<' ';
        
        for(int i=0; i<n; i++){
            
            if(right[i] == -1) return arr[i];
            int x = 0;
            if(left[i] == -1 and i != 0) x = 1;
            else x = i - left[i] - 1;
            
            x += right[i] - i - 1;
            if(x >= k) return arr[i];
        }
        
        return -1;
    }
};