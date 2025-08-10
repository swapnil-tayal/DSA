class Solution {
public:

    bool reorderedPowerOf2(int n) {
        
        string strN = to_string(n);
        sort(strN.begin(), strN.end());
        for(int a=1; a<(1e9); a = a*2){
            
            string str = to_string(a);
            sort(str.begin(), str.end());
            if(str == strN) return 1;

        }
        return 0;
    }
};