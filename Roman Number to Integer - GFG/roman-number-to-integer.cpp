//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
  
    int get(char ch){
        
        if(ch == 'I') return 1;
        if(ch == 'V') return 5;
        if(ch == 'X') return 10;
        if(ch == 'L') return 50;
        if(ch == 'C') return 100;
        if(ch == 'D') return 500;
        if(ch == 'M') return 1000;
    }
  
    int romanToDecimal(string &str) {
        // code here
        int ans = 0;
        int n = str.size();
        
        for(int i=0; i<n-1; i++){
            
            if(get(str[i]) < get(str[i+1])) ans -= get(str[i]);
            else ans += get(str[i]);
        }
        ans += get(str[n-1]);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends