class MedianFinder {
    
    priority_queue<int> maxQ;
    priority_queue<int, vector<int>, greater<int>> minQ;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(maxQ.size() == 0 || maxQ.top() > num) maxQ.push(num);
        else minQ.push(num);
        
        if(maxQ.size() + 1 < minQ.size()){
            maxQ.push(minQ.top());
            minQ.pop();
        }
        if(minQ.size() + 1 < maxQ.size()){
            minQ.push(maxQ.top());
            maxQ.pop();
        }
    }
    
    double findMedian() {
        
        if((maxQ.size() + minQ.size()) % 2 == 0){    
            return ((double)minQ.top() + (double)maxQ.top()) / 2.0;
        
        }else{
            
            if(maxQ.size() > minQ.size()) return maxQ.top();
            else return minQ.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */