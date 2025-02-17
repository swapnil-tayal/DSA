class Solution {
    set<string> st;
public:
    void f(int n, map<char,int> mp, string str){
        if(n == 0){
            cout<<str<<' ';
            st.insert(str);
            return;
        }
        for(auto i: mp){
            if(i.second == 0) continue;
            mp[i.first]--;
            f(n-1, mp, str + i.first);
            mp[i.first]++;
        }
        return;
    }
    int numTilePossibilities(string tiles) {

        map<char,int> mp;
        for(auto i: tiles) mp[i]++;
        int n = tiles.size();
        for(int i=1; i<=n; i++){
            f(i, mp, "");
        }
        return st.size();

    }
};