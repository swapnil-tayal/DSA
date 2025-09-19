class Spreadsheet {
    map<string, int> mp;
public:
    Spreadsheet(int rows) {}
    void setCell(string cell, int value) { 
        mp[cell] = value; 
    }
    void resetCell(string cell) { 
        mp[cell] = 0; 
    }

    int getValue(string s) {
        s = s.substr(1);
        size_t pos = s.find('+');
        string s1 = s.substr(0, pos);
        string s2 = s.substr(pos + 1);
        int left = s1[0] >= 'A' && s1[0] <= 'Z' ? mp[s1] : stoi(s1);
        int right = s2[0] >= 'A' && s2[0] <= 'Z' ? mp[s2] : stoi(s2);
        return left + right;
    }
};