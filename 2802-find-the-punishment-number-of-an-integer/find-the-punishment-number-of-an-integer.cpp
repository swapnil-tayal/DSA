class Solution {
public:

    int f(int i, string num, int tar, int sum){

        if(i == num.size()){
            if(sum == tar) return 1;
            else return 0;
        }
        int x = 0;
        int ans = 0;
        for(int k=i; k<num.size(); k++){
            x = x*10 + (num[k]-'0');
            ans = ans || f(k+1, num, tar, sum + x);
        }
        return ans;
    }

    int punishmentNumber(int n) {
        
        int sum = 0;
        for(int i=1; i<=n; i++){
            if(f(0, to_string(i*i), i, 0)){
                sum += (i*i);
            }
        }
        return sum;
    }
};