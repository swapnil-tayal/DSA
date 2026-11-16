class Solution {
public:
    string digitSum(string s, int k) {
        

        while(s.size() > k){
            string str = "";
            int n = s.size();
            for(int i=0; i<n; i+=k){
                int sum = 0;
                for(int j=i; j<min((int)s.size(), i+k); j++){
                    sum += (s[j] - '0');
                }
                str += to_string(sum);
            }
            s = str;
        }
        return s;
    }
};