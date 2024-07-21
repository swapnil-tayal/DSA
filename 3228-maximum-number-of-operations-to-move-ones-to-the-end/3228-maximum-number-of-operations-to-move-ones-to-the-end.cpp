class Solution {
public:
    int maxOperations(string s) {
        
        while(s.size() and s.back() == '1') s.pop_back();
        
        vector<int> a;
        int i = 0;
        int n = s.size();
        while(i < n){
            
            if(s[i] == '1'){
                int cnt = 0;
                while(i < n and s[i] == '1'){
                    i++;
                    cnt++;
                }
                a.push_back(cnt);
            }else i++;
        }
        
        int sum = 0;
        if(a.size()) sum = a[0]; 
        for(int i=1; i<a.size(); i++){
            a[i] = a[i-1] + a[i];
            sum += a[i];
        }
        return sum;
    }
};