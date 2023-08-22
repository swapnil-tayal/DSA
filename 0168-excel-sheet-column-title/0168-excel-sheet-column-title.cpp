class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string str;
        while(columnNumber >= 1){
            
            columnNumber--;
            int k = columnNumber%26;
            str += char(k+'A');
            columnNumber /= 26;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};