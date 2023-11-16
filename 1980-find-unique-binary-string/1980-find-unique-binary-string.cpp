class Solution {
public:
    
    int f(string n){
        string num = n; 
        int dec_value = 0; 
        int base = 1; 
        int len = num.length(); 
        for (int i = len - 1; i >= 0; i--) { 
            if (num[i] == '1') 
                dec_value += base; 
            base = base * 2; 
        } 
        return dec_value; 
    } 
    string f2(int num){ 
        string str; 
        while(num){ 
            if(num & 1) // 1 
                str = '1' + str; 
            else // 0 
                str = '0' + str; 
          num>>=1; // Right Shift by 1   
        }     
        return str; 
    } 
    
    string findDifferentBinaryString(vector<string>& nums) {
        
        set<int> st;
        for(auto i: nums) st.insert(f(i));
        // for(auto i: st) cout<<i<<' ';
        // cout<<'\n';
        int sz = nums[0].size();
        
        for(int i=0; i<=70000; i++){
            if(st.count(i) == 0){
                string s = f2(i);
                // cout<<i<<' ';
                while(s.size() < sz) s = "0" + s;
                return s;
            }
        }
        return "";
    }
};