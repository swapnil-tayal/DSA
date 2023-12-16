char* removeDuplicateLetters(char* s) {
    
    int n = strlen(s);
    int mp[26] = {0};
    for(int i=0; i<n; i++){
        mp[s[i]-'a'] = i;
    }
    
    char* res = (char*)malloc((n+1)*sizeof(char));
    int resSize = 0;
    int vis[26] = {0};
    
    for(int i=0; i<n; i++){
        
        if(vis[s[i] - 'a']) continue;
        if(resSize == 0 || res[resSize-1] < s[i]){
            
            res[resSize++] = s[i];
            vis[s[i]-'a'] = 1;
        
        }else{
            
            while(resSize > 0 && res[resSize-1] > s[i]){
                
                int ind = mp[res[resSize-1]-'a'];
                if(ind > i){
                    vis[res[--resSize]-'a'] = 0;
                    
                }else break;
            }
            res[resSize++] = s[i];
            vis[s[i]-'a'] = 1;
        }
    }
    res[resSize] = '\0';
    return res;
}