class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        int n = quality.size();
        double ans = 1e9;
        
        vector<pair<double, int>> arr;
        for(int i=0; i<n; i++){
            
            double x = (double)wage[i] / (double)quality[i];
            arr.push_back({ x, quality[i] });
        }
        sort(arr.begin(), arr.end());
        priority_queue<int> pq;
        int qSum = 0;
        
        for(auto &i: arr){
            
            qSum += i.second;
            pq.push(i.second);
            if(pq.size() > k){
                
                qSum -= pq.top();
                pq.pop();
            
            }if(pq.size() == k) ans = min(ans, qSum * i.first);
        }
        return ans;
    }
};