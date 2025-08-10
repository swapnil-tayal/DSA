class Solution {
    vector<int> p;
    map<int,int> mpn;
public:

    int f(int r){

        for(auto &i: p){
            string str = to_string(i);
            if(str.size() == r){
                map<int,int> mpi;
                for(auto k: str) mpi[k]++;
                for(auto k: mpn){
                    mpi[k.first] -= k.second;
                    if(mpi[k.first] == 0) mpi.erase(k.first);
                }
                if(mpi.size() == 0) return 1;
            }
        }
        return 0;
    }

    bool reorderedPowerOf2(int n) {
        
        for(int a=1; a<(1e9); a = a*2){
            p.push_back(a);
        }
        string str = to_string(n);
        for(auto i: str) mpn[i]++;
        return f(str.size());
    }
};