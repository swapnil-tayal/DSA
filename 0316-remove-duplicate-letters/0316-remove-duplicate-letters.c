char* removeDuplicateLetters(char* s) {
    
    int n = strlen(s);
    char* st = (char*)malloc((1000000)*sizeof(char));
    int ind = -1;
    
    int mp[26] = {0};
    int vis[26] = {0};
    for(int i=0; i<n; i++){
        mp[s[i]-'a'] = i;
    }
    
    for(int i=0; i<n; i++){
        
        if(vis[s[i]-'a']) continue;
        // printf("%c\n", s[i]);
        
        if(ind == -1 || st[ind] < s[i]){
            st[++ind] = s[i];
            vis[s[i]-'a'] = 1;
        
        }else{
            
            while(ind >= 0 && st[ind] >= s[i]){
                
                int k = mp[st[ind] - 'a'];
                if(k > i){
                    // printf("%c ", st[ind]);
                    vis[st[ind] - 'a'] = 0;
                    ind--;
                }else break;
            }
            st[++ind] = s[i];
            vis[s[i]-'a'] = 1;
        }
    }
    st[ind+1] = '\0';
    return st;
}