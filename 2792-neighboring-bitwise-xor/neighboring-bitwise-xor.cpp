class Solution {
public:

    int f(int i, int curr, int fir, vector<int> &a){

        if(i == a.size()-1){
            return (curr xor fir) == a[i];
        }
        int ans = 0;
        if(i == 0){
        
            if(a[i] == 0) ans = f(i+1, 0, 0, a) or f(i+1, 1, 1, a); 
            else ans = f(i+1, 1, 0, a) or f(i+1, 0, 1, a);     
        
        }else{

            if(a[i] == 1){
                if(curr == 1) ans = f(i+1, 0, fir, a);
                else ans = f(i+1, 1, fir, a);
            }else{
                if(curr == 1) ans = f(i+1, 1, fir, a);
                else ans = f(i+1, 0, fir, a);    
            }
        }
        return ans;
    }

    bool doesValidArrayExist(vector<int>& derived) {
        
        return f(0, 0, 0, derived);
    }
};