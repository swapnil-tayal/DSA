typedef struct Trie
{
    struct Trie* trieMap[26];
    bool isWord;
} Trie;


Trie* trieCreate()
{
    Trie* t = malloc(sizeof(Trie));
    for(int i = 0; i < 26; i++)
        t->trieMap[i] = NULL;
    t->isWord = false;
    return t;    
}

void trieInsert(Trie* obj, char * word)
{
    Trie* currObj = obj;
    for(int i = 0; word[i] != '\0'; i++)
    {
        char c = word[i] - 'a';
        if(currObj->trieMap[c] == NULL)
            currObj->trieMap[c] = trieCreate();
        currObj = currObj->trieMap[c];
    }
    currObj->isWord = true;
}

bool trieSearch(Trie* obj, char * word)
{
    Trie* currObj = obj;
    for(int i = 0; word[i] != '\0'; i++)
    {
        char c = word[i] - 'a';
        if(currObj->trieMap[c] == NULL)
            return false;
        currObj = currObj->trieMap[c];
    }
    return currObj->isWord ? true : false;
}

bool trieStartsWith(Trie* obj, char * prefix)
{
    Trie* currObj = obj;
    for(int i = 0; prefix[i] != '\0'; i++)
    {
        char c = prefix[i] - 'a';
        if(currObj->trieMap[c] == NULL)
            return false;
        currObj = currObj->trieMap[c];
    } 
    return true; 
}

void trieFree(Trie* obj)
{
    Trie* currObj = obj;
    for(int i = 0; i < 26; i++)
        if(currObj->trieMap[i] != NULL)
            trieFree(currObj->trieMap[i]);
    free(obj);
}