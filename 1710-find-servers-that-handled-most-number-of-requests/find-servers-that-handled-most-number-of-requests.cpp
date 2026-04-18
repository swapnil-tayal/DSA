class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pqLoad;
        set<int> st;

        vector<int> handled(k, 0);
        for(int i=0; i<k; i++) st.insert(i);
        int maxi = 0;

        for(int i=0; i<arrival.size(); i++){

            while(pqLoad.size() && pqLoad.top().first <= arrival[i]){
                st.insert(pqLoad.top().second);
                pqLoad.pop();
            }

            if(st.size() == 0) continue;
            auto ptr = st.lower_bound((i%k));
            int availableServer = ptr != st.end() ? *ptr : *st.begin();
            handled[availableServer]++;
            st.erase(availableServer);

            maxi = max(maxi, handled[availableServer]);
            pqLoad.push({ arrival[i] + load[i], availableServer });
        
        }
        vector<int> res;
        for(int i=0; i<k; i++){
            // cout<<handled[i]<<' ';
            if(handled[i] == maxi) res.push_back(i);
        }
        return res;
    }
};