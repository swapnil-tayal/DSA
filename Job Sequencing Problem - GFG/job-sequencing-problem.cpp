//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
bool cmp(Job j1, Job j2){
    return j1.profit > j2.profit;
}
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n){ 
        // your code here
        
        sort(arr, arr+n, cmp);
        
        int maxiDead = 0;
        for(int i=0; i<n; i++){
            maxiDead = max(maxiDead, arr[i].dead);
        }
        vector<int> last(maxiDead+1, 0);
        int cnt = 0;
        int ans = 0;
        
        for(int i=0; i<n; i++){
            
            int dead = arr[i].dead;
            while(dead >= 1){
                if(last[dead] == 0){
                    last[dead] = 1;
                    cnt ++;
                    ans += arr[i].profit;
                    break;
                }else dead--;
            }
        }
        return { cnt, ans }; 
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends