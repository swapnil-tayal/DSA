class Solution {
public:
    int minimumOperations(string num) {
        
        int cnt1 = 0, cnt2 = 0;
        int n = num.size();
        int i = n-1;
        
        if(n == 1) return 1;
        if(n == 2 and num[0] != '0' and num[1] != '0' and num != "25" and num != "75") return 2;
        
        while(i >= 0 and num[i] != '0'){
            i--;
            cnt1++;    
        }
        if(i >= 0 and num[i] == '0'){
            i--;
            while(i >= 0 and num[i] != '0' and num[i] != '5'){
                i--;
                cnt1++;
            }
        }
        i = n-1;
        while(i >= 0 and num[i] != '5'){
            i--;
            cnt2++;    
        }
        if(i == 0) cnt2 = n;
        else if(i >= 0 and num[i] == '5'){
            i--;
            while(i >= 0 and num[i] != '7' and num[i] != '2'){
                i--;
                cnt2++;
            }
        }
        return min(cnt1, cnt2);
    }
};