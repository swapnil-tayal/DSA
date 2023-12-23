class Solution {
public:
    bool isPathCrossing(string path) {
        
        set<pair<int,int>> st;
        int x = 0;
        int y = 0;
        st.insert({0, 0});
        
        for(auto i: path){
            
            if(i == 'N') y++;
            else if(i == 'S') y--;
            else if(i == 'E') x++;
            else x--;
            
            if(st.count({ x,y })) return true;
            st.insert({ x,y });
        }
        return false;
    }
};