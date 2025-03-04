class Solution {
    set<int> st;
public: 

    void f(){
        for(int i=1; i<=30000; i++){
            int num = 0;
            int ind = 0;
            int x = i;
            while(x > 0){
                if(x%2) num += pow(3, ind);
                ind++;
                x = x/2;
            }
            st.insert(num);
        }
    }
    Solution(){
        f();
    }
    bool checkPowersOfThree(int n) {
        
        return st.count(n);
    }
};