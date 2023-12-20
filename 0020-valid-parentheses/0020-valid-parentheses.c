int f(char a, char b){
    
    if( (a == '(' && b == ')') ||   
        (a == '[' && b == ']') ||
        (a == '{' && b == '}') ) return false;
    return true;
}

bool isValid(char* s) {
    
    char st[10001];
    int ind = -1;
    
    int n = strlen(s);
    for(int i=0; i<n; i++){
        
        if(ind == -1 || f(st[ind], s[i])){
            st[++ind] = s[i];
        }else{
            ind--;
        }
    }
    return ind == -1;
}