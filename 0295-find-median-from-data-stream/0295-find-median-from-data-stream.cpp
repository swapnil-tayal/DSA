class MedianFinder{
    
    priority_queue<int, vector<int>, greater<int>> minPq;
    priority_queue<int> maxPq;
    int cnt;
public:
    MedianFinder() {
        this->cnt = 0;
    }
    
    void addNum(int num) {
        
        if(maxPq.empty() || num < maxPq.top()) maxPq.push(num);
        else minPq.push(num);
        
        if(minPq.size() > maxPq.size() + 1){
            maxPq.push(minPq.top());
            minPq.pop();
        }
        else if(maxPq.size() > minPq.size() + 1){
            minPq.push(maxPq.top());
            maxPq.pop();
        }
    }
    
    double findMedian() {
        
        if((minPq.size() == maxPq.size())){
            
            double x = minPq.top() + maxPq.top();
            return x/2.0;
            
        }else{
            return minPq.size() > maxPq.size() ? minPq.top() : maxPq.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */