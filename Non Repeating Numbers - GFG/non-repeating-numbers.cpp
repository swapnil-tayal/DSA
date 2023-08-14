//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums){
        // Code here.
        
        int n = nums.size();
        int xr = 0;
        for(auto &i: nums) xr ^= i;
        
        int k=(xr&(~(xr-1)));
        int set1=0,set2=0;
        for(auto it:nums){
            if(k&it){
                set1^=it;
            }else{
                set2^=it;
            }
        }
        return {min(set1,set2),max(set1,set2)};
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends