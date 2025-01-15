class Solution {
public:
    int minimizeXor(int num1, int num2) {
        
        int bits = 0;
        while(num2 > 0){
            bits += num2 % 2;
            num2 /= 2;
        }
        vector<int> a, b;
        while(num1 > 0){
            a.push_back(num1 % 2);
            num1 /= 2;
        }
        reverse(a.begin(), a.end());
        for(auto i: a){
            if(i == 1 and bits){
                bits--;
                b.push_back(1);
            }else{
                b.push_back(0);
            }
        }
        for(int i=b.size()-1; i>=0; i--){
            if(b[i] == 0 and bits){
                b[i] = 1;
                bits--;
            }
        }
        while(bits--){
            b.insert(b.begin(), 1);
        }
        int ans = 0;
        int ind = 0;
        for(int i=b.size()-1; i>=0; i--){
            if(b[i] == 1) ans += pow(2, ind);
            ind++;
        }
        return ans;
    }
};