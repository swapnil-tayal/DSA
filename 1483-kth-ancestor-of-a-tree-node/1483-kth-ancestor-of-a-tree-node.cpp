class TreeAncestor {
    
    vector<vector<int>> table;
public:
    TreeAncestor(int n, vector<int>& parent) {
        
        table.resize(n, vector<int>(20, -1));
        
        for(int i=0; i<n; i++){    
            table[i][0] = parent[i];
        }
        for(int j=1; j<20; j++){
            for(int i=0; i<n; i++){

                if(table[i][j-1] == -1) table[i][j] = -1;
                else table[i][j] = table[table[i][j-1]][j-1];
            }
        }
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<3; j++){
        //         cout<<table[i][j]<<' ';
        //     }cout<<'\n';
        // }
    }
    
    int getKthAncestor(int node, int k) {
        
        int x = node;
        for(int i=0; i<20; i++){
            
            int mask = (1<<i);
            if((k & mask) > 0){
                
                x = table[x][i];
                if(x == -1) return -1;
            }
        }
        return x;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */