class Solution {
public:

    char kthCharacter(long long k, vector<int>& operations) {
        
        vector<long long> a;
        long long len = 1;

        for(auto i: operations){
            len = len * 2;
            a.push_back(len);
            if(len >= k) break;
        }
        int nxt = 0;
        for(int i=a.size()-1; i>=0; i--){

            long long half = a[i]/2;
            if(k > half){
                k = k - half;
                if(operations[i] == 1) nxt++;
            }
        }
        return char((char('a')+((nxt+26)%26)));
    }
};