class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& arr) {
        
        
        vector<int> wait;
        int n = arr.size();
        int currTime = 0;
        
        for(int i=0; i<n; i++){
            
            int arrTime = arr[i][0];
            int cook = arr[i][1];
            
            if(arrTime > currTime){
                
                wait.push_back(cook);
                currTime = arrTime + cook;
                
            }else{
                
                wait.push_back(currTime - arrTime + cook);
                currTime = currTime + cook;
                
            }
        }
        double ans = 0;
        for(auto i: wait) ans += i;
        // for(auto i: wait) cout<<i<<' ';
        // cout<<'\n';
        ans /= double(wait.size());
        return ans;
        
    }
};