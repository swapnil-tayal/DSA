int longestValidParentheses(char* s) {
    
    int n = strlen(s);
    int st[100000];
    int ind = -1;
    int ans = 0;
    
    for(int i=0; i<n; i++){
        // printf("%d ", ind);
        if(ind == -1){
            st[++ind] = i;
        }
        else{
            if(s[st[ind]] == '(' && s[i] == ')') ind--;
            else{
                st[++ind] = i;
            }
        }
        int val = 0;
        if(ind == -1) val = i+1;
        else{
            val = i - st[ind];
        }
        if(ans < val) ans = val;
    }
    return ans;
}