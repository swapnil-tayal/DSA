class Solution {
    vector<int> present;
    vector<int> future;

    vector<vector<vector<int>>> dpNode;
    vector<vector<vector<vector<int>>>> dpChild;

public:

    int goNode(int src, int parBought, vector<vector<int>>& adj, int budget){

        if(dpNode[src][parBought][budget] != -1) return dpNode[src][parBought][budget];

        int notBuy = goChild(src, 0, 0, adj, budget);

        int buy = INT_MIN;
        int currValue = parBought ? present[src]/2 : present[src];

        if(budget >= currValue) {
            buy = future[src] - currValue + goChild(src, 0, 1, adj, budget - currValue);
        }

        return dpNode[src][parBought][budget] = max(buy, notBuy);
    }

    int goChild(int src, int currIndex, int parBought, vector<vector<int>>& adj, int budget){

        if(currIndex >= adj[src].size()) return 0;

        if(dpChild[src][currIndex][parBought][budget] != -1) return dpChild[src][currIndex][parBought][budget];

        int node = adj[src][currIndex];
        int ans = INT_MIN;

        for(int i = 0; i <= budget; i++){
            ans = max(ans, goNode(node, parBought, adj, i) + goChild(src, currIndex+1, parBought, adj, budget-i));
        }

        return dpChild[src][currIndex][parBought][budget] = ans;
    }

    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {

        this->present = present;
        this->future = future;

        vector<vector<int>> adj(n);
        int maxEdges = 0;
        for(auto &i: hierarchy){
            adj[i[0]-1].push_back(i[1]-1);
            maxEdges = max(maxEdges, (int)adj[i[0]-1].size()); 
        }

        dpNode.resize(n, vector<vector<int>>(2, vector<int>(budget+1, -1)));
        dpChild.resize(n, vector<vector<vector<int>>>(maxEdges+1, vector<vector<int>>(2, vector<int>(budget+1, -1))));

        return goNode(0, 0, adj, budget);
    }
};
