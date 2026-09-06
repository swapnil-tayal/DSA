class StockPrice {
    int maxTime = 0;
    map<int,int> mp;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pqMin;
    priority_queue<pair<int,int>> pqMax;
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        mp[timestamp] = price;
        maxTime = max(maxTime, timestamp);
        pqMin.push({ price, timestamp });
        pqMax.push({ price, timestamp });
    }
    
    int current() {
        return mp[maxTime];
    }
    
    int maximum() {
        while(mp[pqMax.top().second] != pqMax.top().first) pqMax.pop();
        return pqMax.top().first;
    }
    
    int minimum() {
        while(mp[pqMin.top().second] != pqMin.top().first) pqMin.pop();
        return pqMin.top().first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */