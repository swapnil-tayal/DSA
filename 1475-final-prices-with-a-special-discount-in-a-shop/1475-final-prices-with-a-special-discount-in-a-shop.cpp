class Solution {
public:
    vector<int> findNextSmallerElement(const std::vector<int>& arr) {   
        vector<int> result(arr.size(), 0); 
        
        
        stack<int> st;  
        for (int i = 0; i < arr.size(); ++i) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                result[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }

        return result;
    }
    vector<int> finalPrices(vector<int>& prices) {
        
        int n = prices.size();
        vector<int> a = findNextSmallerElement(prices);
        for(int i=0; i<n; i++){
            prices[i] -= a[i];
        }
        return prices;
    }
};