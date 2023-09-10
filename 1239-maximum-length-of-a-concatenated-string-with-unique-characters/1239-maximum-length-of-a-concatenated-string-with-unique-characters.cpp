class Solution {
public:
    
    int solve(vector<string> &arr, int n, string temp, map<string, int> &dp){
        
        set<int> st;
        for(auto i: temp){
            if(st.count(i)) return -1;
            st.insert(i);
        }
        if(n == -1) return st.size();
        
        string str;
        str += to_string(n);
        str += temp;
        
        // if(dp.count(str)) return dp[str];
        
        int pick = solve(arr, n-1, temp+arr[n], dp);
        int npick = solve(arr, n-1, temp, dp);
        return dp[str] = max(pick, npick);
    }
    
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        map<string, int> dp;
        return solve(arr, n-1, "", dp);
    }
};