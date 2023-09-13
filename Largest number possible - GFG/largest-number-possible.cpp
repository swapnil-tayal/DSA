//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int n, int s){
        // code here
        
        int k = s/9;
        k += (s%9 != 0);
        // cout<<k<<' ';
        if(n < k || (s == 0 and n > 1)) return "-1";
        
        k = s/9;
        string str;
        while(k > 0){
            str += '9';
            k--;
        }
        if(str.size() < n) str += to_string(s%9);
        while(str.size() < n) str += '0';
        return str;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends