class Solution {
public:
    
    int solve(vector<string> &arr, int n, string temp){
        
        set<int> st;
        for(auto i: temp){
            if(st.count(i)) return -1;
            st.insert(i);
        }
        if(n == -1) return st.size();
        
        int pick = solve(arr, n-1, temp+arr[n]);
        int npick = solve(arr, n-1, temp);
        return max(pick, npick);
    }
    
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        return solve(arr, n-1, "");
    }
};