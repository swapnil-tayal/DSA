class Solution {
public:
    
    int f(int mid, vector<int> &h, int bricks, int ladders){
        
        int n = h.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=1; i<=mid; i++){
            if(h[i] > h[i-1]) pq.push(h[i] - h[i-1]);
        }
        
        int sum = 0;
        while(!pq.empty()){
            
            if(sum + pq.top() > bricks) break;
            sum += pq.top();
            pq.pop();
            
        }
        return pq.size() <= ladders;
    }
    
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int n = heights.size();
        int s = 1;
        int e = n-1;
        int ans = 0;
        
        while(s <= e){
            
            int mid = (s+e)/2;
            if(f(mid, heights, bricks, ladders)){
                ans = mid;
                s = mid+1;
            }else e = mid-1;
        }
        return ans;
    }
};