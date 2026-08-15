class Solution {
public:

    int f(string &s){

        int n = s.size();
        int val = 0;
        for(int i=0; i<n/2; i++){

            int ch1 = s[i] - 'a';
            int ch2 = s[n-i-1] - 'a';
            if(ch1 > ch2) swap(ch1, ch2);
            val += min(ch2-ch1, 26-ch2+ch1);
        }
        // cout<<s<<' '<<val<<'\n'; 
        return val;
    }

    int minOperations(string s) {
        
        int n = s.size();
        s = s + s;
        int opr = 0;
        int minOpr = 1e9;

        for(int i=0; i<n; i++){

            opr = i;
            string temp = s.substr(i, n);
            opr += f(temp);
            minOpr = min(minOpr, opr);
        }
        return minOpr;
    }
};