class Solution {
public:
    
    int fact(unsigned int n){ 
        if (n == 0) 
            return 1; 
        return n * fact(n - 1); 
    } 
    
    string getPermutation(int n, int k) {
        
        vector<int> num;
        // int fact = 1;
        for(int i=1; i<n; i++){
            // fact = fact*i;
            num.push_back(i);
        }
        num.push_back(n);
        string ans = "";
        k--;
        while(true){    
            
            ans += to_string(num[ k / fact(n-1) ]);
            num.erase(num.begin() + k / fact(n-1));
            if(num.size() == 0) break;
            k = k % fact(n-1);
            n--;
            
        }
        return ans;
    }
};