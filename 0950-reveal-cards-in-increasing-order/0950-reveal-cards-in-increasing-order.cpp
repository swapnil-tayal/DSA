class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        int n = deck.size();
        sort(deck.begin(), deck.end());
        
        deque<int> dq;
        for(int i=0; i<n; i++){
            dq.push_back(i);
        }
        
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            
            int ind = dq.front();
            dq.pop_front();
            
            ans[ind] = deck[i];
            
            ind = dq.front();
            dq.pop_front();
            dq.push_back(ind);
        }
        return ans;
    }
};