class Solution {
public:

    int f(vector<int> &height, int chk){

        stack<int> st;
        int n = height.size();

        vector<int> pre(n);
        pre[0] = height[0];
        for(int i=1; i<n; i++) pre[i] = pre[i-1] + height[i];

        int ans = 0;
        for(int i=n-1; i>=0; i--){
            while(st.size() and ((chk && height[i] >= height[st.top()]) || height[i] > height[st.top()])){
                int sz = st.top() - i - 1;
                if(sz > 0) ans += (height[st.top()] * sz) - (pre[st.top()-1] - pre[i]);
                st.pop();
            }
            if(st.size() == 0) st.push(i);
            else if(chk && height[st.top()] <= height[i]) st.push(i);
            else if(height[st.top()] < height[i]) st.push(i);
        }
        return ans;
    }

    int trap(vector<int>& height) {
        
        int ans = f(height, 1);
        reverse(height.begin(), height.end());
        ans += f(height, 0);
        return ans;
    }
};

// 5 5 1 7 1 1 5 2 7 6