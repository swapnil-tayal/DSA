class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        int n = profits.size();
        priority_queue<pair<int,int>> pq;
        
        int money = w;
        vector<pair<int,int>> a;
        for(int i=0; i<n; i++){
            a.push_back({ capital[i], profits[i] });
        }
        sort(a.begin(), a.end());
        for(int i=0; i<n; i++){
            profits[i] = a[i].second;
            capital[i] = a[i].first;
        }
        
        int ind = upper_bound(capital.begin(), capital.end(), money) - capital.begin();
        if(ind == n || capital[ind] > money) ind--;
        int lastInd = 0;
        
        for(int i=lastInd; i<=ind; i++){
            if(capital[i] <= w) pq.push({ profits[i], capital[i] });
            else break;
        }
        
        int ans = w;
        while(k-- and pq.size()){
            
            ans += pq.top().first;
            money += pq.top().first;
            
            pq.pop();
            
            lastInd = ind+1;
            ind = upper_bound(capital.begin(), capital.end(), money) - capital.begin();
            if(ind == n || capital[ind] > money) ind--;
            
            for(int i=lastInd; i<=ind; i++){
                pq.push({ profits[i], capital[i] });
            }
        }
        return ans;
    }
};