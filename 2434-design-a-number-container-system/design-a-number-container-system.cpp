class NumberContainers {
    unordered_map<int,set<int>> mp;
    unordered_map<int,int> mp2;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        int prevNum = -1;
        if(mp2.find(index) != mp2.end()){
            int prevNum = mp2[index];
            mp[prevNum].erase(index);
            if(mp[prevNum].size() == 0) mp.erase(prevNum);
        }
        mp[number].insert(index);
        mp2[index] = number;
    }
    
    int find(int number) {
        if(mp.find(number) != mp.end()){
            return *mp[number].begin();
        }else return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */