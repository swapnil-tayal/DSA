class RandomizedSet {
    
    vector<int> arr;
    map<int, int> mp;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        
        if(mp.find(val) != mp.end()){
            return false;
        }
        arr.push_back(val);
        mp[val] = arr.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        
        if(mp.find(val) == mp.end()){
            return false;
        }
        
        int ind = mp[val];
        int valueToRemoved = arr[ind];
        
        int lastInArray = arr[arr.size()-1];
        
        mp[lastInArray] = ind;
        arr[ind] = lastInArray;
        
        arr[arr.size()-1] = valueToRemoved;
        arr.pop_back();
        
        mp.erase(valueToRemoved);
        
        return true;
    }
    
    int getRandom() {
        
        auto it = arr.cbegin();
        int random = rand() % arr.size();
        return *(it + random);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */