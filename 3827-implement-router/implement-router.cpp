#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
// duplicate allowed
using ordered_set2 = tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>;

class Router {
    set<vector<int>> st;
    map<int, ordered_set2> mp;
    deque<vector<int>> dq;
    int limit = 0;
public:
    Router(int memoryLimit) {
        limit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if(st.count({ source, destination, timestamp})) return false;
        if(dq.size() == limit){
            auto a = dq.front();
            mp[a[1]].erase(mp[a[1]].begin());
            st.erase(dq.front());
            dq.pop_front();
        }
        st.insert({ source, destination, timestamp });
        mp[destination].insert(timestamp);
        cout<<mp[destination].size()<<'\n';
        dq.push_back({source, destination, timestamp});
        return true;
    }
    
    vector<int> forwardPacket() {
        if(dq.size()){
            auto a = dq.front();
            dq.pop_front();
            st.erase(a);
            mp[a[1]].erase(mp[a[1]].begin());
            return a;
        }
        else return {};
    }
    
    int getCount(int destination, int startTime, int endTime) {
            
        auto it1 = mp[destination].order_of_key(startTime);
        auto it2 = mp[destination].order_of_key(endTime+1);
        int count = it2 - it1;
        return count;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */