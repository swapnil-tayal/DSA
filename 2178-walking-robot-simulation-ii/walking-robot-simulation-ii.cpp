class Robot {
    int n,m;
    string dir = "East";
    int x;
    int y;

    string getDir(string str){

        if(str == "North") str = "West";
        else if(str == "West") str = "South";
        else if(str == "South") str = "East";
        else str = "North";
        return str;
        
    }

    vector<int> getNext(int x, int y, string dir){

        if(dir == "North") return {x, y+1};
        else if(dir == "South") return {x, y-1};
        else if(dir == "East") return {x+1, y};
        else return {x-1, y};

    }

    int remDis(int x, int y, string dir){
        if(dir == "East") return m-x;
        else if(dir == "North") return n-y;
        else if(dir == "West") return x;
        else return y;
    }

public:
    Robot(int width, int height) {
        n = height;
        m = width;
        x = 0;
        y = 0;
    }
    
    void step(int num) {
        
        int perimeter = 2 * (m - 1) + 2 * (n - 1);
        num = num % perimeter;

        if (num == 0) {
            if (x == 0 && y == 0) dir = "South";
        }
        while(num--){
            vector<int> next = getNext(x, y, dir);
            while(next[0] < 0 || next[1] < 0 || next[0] == m || next[1] == n) {
                dir = getDir(dir);
                next = getNext(x, y, dir);
            }
            x = next[0];
            y = next[1];
        }
    }
    
    vector<int> getPos() {
        
        return {x, y};
    }
    
    string getDir() {
        return dir;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */