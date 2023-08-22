//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        int maxi = 0;
        for(int i=0; i<n; i++){
            int sm = 0;
            for(int j=0; j<n; j++){
                sm += matrix[i][j];
            }
            maxi = max(maxi, sm);
        }
        
        for(int j=0; j<n; j++){
            int sm = 0;
            for(int i=0; i<n; i++){
                sm += matrix[i][j];
            }
            maxi = max(maxi, sm);
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            int sm = 0;
            for(int j=0; j<n; j++){
                sm += matrix[i][j];
            }
            cnt += max(0, maxi - sm);
        }
        
        for(int j=0; j<n; j++){
            int sm = 0;
            for(int i=0; i<n; i++){
                sm += matrix[i][j];
            }
            cnt += max(0, maxi - sm);
        }
        return cnt/2;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends