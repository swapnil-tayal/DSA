class Solution {
public:
    int minDeletions(string s) {
        
        map<char,int> mp;
        for(auto i: s) mp[i]++;
    
        vector<int> a;
        for(auto i: mp) a.push_back(i.second);
        sort(a.rbegin(), a.rend());
        
        set<int> st;
        int cnt = 0;
        
        for(auto i: a){
            
            if(st.count(i)){
                
                int x = i;
                while(st.count(x) and x > 0){
                    x--;
                    cnt++;
                }
                st.insert(x);
                
            }else st.insert(i);
        }
        return cnt;
    }
};