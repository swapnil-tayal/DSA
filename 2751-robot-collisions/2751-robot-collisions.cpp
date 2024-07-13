class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        
        int n = directions.size();
        vector<pair<int, pair<int, char>>> a;
        
        for(int i=0; i<n; i++){
            a.push_back({positions[i], {healths[i], directions[i]}});
        }
        
        sort(a.begin(), a.end());
        
        vector<int> newPos;
        for(int i=0; i<n; i++){
            newPos.push_back(a[i].first);
            healths[i] = a[i].second.first;
            directions[i] = a[i].second.second;
        }
        
        // for(auto i: newPos) cout<<i<<' ';
        // cout<<'\n';
        // for(auto i: healths) cout<<i<<' ';
        // cout<<'\n';
        // for(auto i: directions) cout<<i<<' ';
        // cout<<'\n';
        
        stack<pair<int,pair<char,int>>> st;
        for(int i=0; i<n; i++){
            
            if(st.empty()) st.push({ healths[i], {directions[i], newPos[i]} });
            else{
                if(directions[i] == 'R'){
                    st.push({ healths[i], {directions[i], newPos[i]} });
                }else{
                    if(st.top().second.first == 'R' and st.top().first > healths[i]){
                        st.top().first--;
                    }else{
                        while(st.size() and st.top().second.first == 'R' and st.top().first <= healths[i]){
                            if(healths[i] == st.top().first){
                                healths[i] = -1;
                                st.pop();
                                break;
                            }else{
                                healths[i] -= 1;
                                st.pop();
                            }   
                        }
                        if(st.size() and st.top().second.first == 'R' and st.top().first > healths[i] and healths[i] != -1){
                            st.top().first--;
                        }else if(healths[i] != -1){
                            st.push({ healths[i], {directions[i], newPos[i]} });
                        }
                    }
                }
            }
        }
        map<int,int> mp;
        while(!st.empty()){
            mp[st.top().second.second] = st.top().first;
            st.pop();
        }
        vector<int> res;
        for(auto i: positions){
            if(mp.count(i)) res.push_back(mp[i]);
        }
        return res;
    }
};