class RangeModule {
    map<int,int> ste;
    map<int,int> ets;
public:
    RangeModule() {
        // fuck leetcode
    }
    
    void addRange(int left, int right) {

        if(left >= right) return;
        right--;

        auto indS = ste.lower_bound(left);
        auto indE = ets.lower_bound(left);

        set<int> startInBtn, endInBtn;

        while(indS != ste.end() && indS->first <= right) {
            startInBtn.insert(indS->first);
            endInBtn.insert(indS->second);
            indS++;
        }

        while(indE != ets.end() && indE->first <= right) {
            endInBtn.insert(indE->first);
            startInBtn.insert(indE->second);
            indE++;
        }

        auto prevS = ste.lower_bound(left);
        if(prevS != ste.begin()) {
            prevS--;
            if(prevS->second >= left) {
                startInBtn.insert(prevS->first);
                endInBtn.insert(prevS->second);
            }
        }

        int maxEnd = right;
        int minStart = left;

        for(auto &i : startInBtn) minStart = min(minStart, i);
        for(auto &i : endInBtn) maxEnd = max(maxEnd, i);
        for(auto &i : startInBtn) ste.erase(i);
        for(auto &i : endInBtn) ets.erase(i);

        ste[minStart] = maxEnd;
        ets[maxEnd] = minStart;
    }
        
    bool queryRange(int left, int right) {
        if(left >= right) return true;
        right--;

        auto it = ste.upper_bound(left);
        if(it == ste.begin()) return false;
        it--;

        if(it->second < left) return false;

        int covered = it->second;
        if(covered >= right) return true;

        it++;
        while(it != ste.end() && it->first <= covered + 1) {
            covered = max(covered, it->second);

            if(covered >= right) return true;
            it++;
        }

        return false;
    }
    
    void removeRange(int left, int right) {

        if(left >= right) return;
        int remEnd = right - 1;
        vector<pair<int,int>> intervals;

        auto indS = ste.lower_bound(left);
        if(indS != ste.begin()) {
            auto prevS = std::prev(indS);
            if(prevS->second >= left) {
                intervals.push_back({prevS->first, prevS->second});
            }
        }

        while(indS != ste.end() && indS->first <= remEnd) {
            intervals.push_back({indS->first, indS->second});
            indS++;
        }

        for(auto [s, e] : intervals) {
            ste.erase(s);
            ets.erase(e);
            if(s < left) {
                ste[s] = left - 1;
                ets[left - 1] = s;
            }
            if(e >= right) {
                ste[right] = e;
                ets[e] = right;
            }
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */