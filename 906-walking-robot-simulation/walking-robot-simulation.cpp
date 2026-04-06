class Solution {
public:

    string getDir(string str, int dir){

        if(dir == -2){
            if(str == "N") str = "W";
            else if(str == "W") str = "S";
            else if(str == "S") str = "E";
            else str = "N";

        }else{
            if(str == "N") str = "E";
            else if(str == "E") str = "S";
            else if(str == "S") str = "W";
            else str = "N";
        }
        return str;
    }

    vector<int> getNext(int x, int y, string dir){

        if(dir == "N") return {x, y+1};
        else if(dir == "S") return {x, y-1};
        else if(dir == "E") return {x+1, y};
        else return {x-1, y};

    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        int n = commands.size();
        string dir = "N";
        int maxX = 0;
        int maxY = 0;
        int x = 0;
        int y = 0;

        set<vector<int>> st;
        for(auto &i: obstacles) st.insert(i);
        int ans = 0;

        for(int i=0; i<n; i++){
            
            if(commands[i] < 0) dir = getDir(dir, commands[i]);
            else{
                int k = commands[i];
                while(k--) {
                    vector<int> nextPair = getNext(x, y, dir);
                    if(st.count(nextPair)) break;
                    x = nextPair[0];
                    y = nextPair[1];
                }
            }
            ans = max(ans, (int)(pow(x, 2) + pow(y, 2)));
        }
        return ans;
    }
};