class Solution {
public:
    string pushDominoes(string dominoes) {
        
        int n = dominoes.size();
        int force = 0;
        vector<int> forces(n, 0);
        for(int i=0; i<n; i++){
            if(dominoes[i] == 'R') force = n;
            else if(dominoes[i] == 'L') force = 0;
            else force = max(force-1, 0);
            forces[i] += force;
        }
        for(int i=n-1; i>=0; i--){
            if(dominoes[i] == 'L') force = n;
            else if(dominoes[i] == 'R') force = 0;
            else force = max(force-1, 0);
            forces[i] -= force;
        }
        string ans;
        for(auto &i: forces){
            if(i > 0) ans += 'R';
            else if(i < 0) ans += 'L';
            else ans += '.';
        }
        return ans;
    }
};