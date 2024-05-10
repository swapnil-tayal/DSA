class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        priority_queue<pair<double, pair<int,int>>, vector<pair<double, pair<int,int>>>, greater<pair<double, pair<int,int>>>> pq;
        int n = arr.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                
                double x = (double)arr[i] / (double)arr[j];
                pq.push({ x, {arr[i], arr[j]} });
            }
        }
        while(k-1 > 0){
            pq.pop();
            k--;
        }
        return { pq.top().second.first, pq.top().second.second };
    }
};