int size = -1;
char arr[10000];

char top(){
    if(size == -1) return '.';
    return arr[size];
}
char pop(){
    if(size == -1) return -1;
    return arr[size--];
}
void push(char ch){
    arr[++size] = ch;
}
bool isEmpty(){
    if(size == -1) return true;
    return false;
}
bool isEqual(char ch1, char ch2){
    
    if(ch1 == '(' && ch2 == ')') return 0;
    if(ch1 == '{' && ch2 == '}') return 0;
    if(ch1 == '[' && ch2 == ']') return 0;
    return 1;
}
bool isValid(char* s) {
    
    size = -1;
    int n = strlen(s);
    int i = 0;
    
    while(i < n){
        // printf("%c %c\n", top(), s[i]);
        if(isEmpty() || isEqual(top(), s[i])){
            push(s[i]);
        
        }else pop();
        i++;
    }
    return isEmpty();
}