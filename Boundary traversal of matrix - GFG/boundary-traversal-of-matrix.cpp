//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
vector<int> boundaryTraversal(vector<vector<int> > mat, int n, int m) 
    {
        vector<int>vec;
        int row=mat.size();
        int col=mat[0].size();
        int top=0,bot=row-1,l=0,r=col-1;
        int d=1;
        while(top<=bot and l<=r and d--){
            for(int i=l;i<=r;i++){
                vec.push_back(mat[top][i]);
            }
            top++;
            for(int i=top;i<=bot;i++){
                vec.push_back(mat[i][r]);
            }
            r--;
            if(top<=bot){
                for(int i=r;i>=l;i--){
                vec.push_back(mat[bot][i]);
            }
            bot--;
                
            }
            if(l<=r){
                for(int i=bot;i>=top;i--){
                vec.push_back(mat[i][l]);
            }
            l++;
                
            }
        }
        return vec;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends