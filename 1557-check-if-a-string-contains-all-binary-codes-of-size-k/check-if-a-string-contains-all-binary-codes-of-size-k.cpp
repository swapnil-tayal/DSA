class Solution {
    unordered_set<string> st;
public:

    int f(int i, int k, string &str){

        if(i == k) return st.count(str);
        
        str += "1";
        int one = f(i+1, k, str);
        str.pop_back();
        if(!one) return false;
        str += "0";
        int zero = f(i+1, k, str);
        str.pop_back();
        return one and zero;
    }

    bool hasAllCodes(string s, int k) {
        
        string str = "";
        if(k > s.size()) return 0;
        for(int i=0; i<s.size()-k+1; i++){
            st.insert(s.substr(i, k));
        }
        // for(auto i: st) cout<<i<<' ';
        return f(0, k, str);
    }
};