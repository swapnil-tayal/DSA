/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator{
    
    queue<int> q;
public:
    
    void f(vector<NestedInteger> &a){
        
        int n = a.size();
        for(int i=0; i<n; i++){
            if(a[i].isInteger()) q.push(a[i].getInteger());
            else{
                f(a[i].getList());
            }
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        f(nestedList);
    }
    
    int next(){
        int x = q.front();
        q.pop();
        return x;
    }
    
    bool hasNext(){
        return q.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */