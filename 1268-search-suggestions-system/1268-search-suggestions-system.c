#define NUM_CHAR 26

typedef struct _trie_node_t {
    struct _trie_node_t *next[NUM_CHAR];
    bool terminated;
    char *text;
} trie_node_t;

trie_node_t *generate_tree_node(void) {
    trie_node_t *node = (trie_node_t *)malloc(sizeof(trie_node_t));
    for(int i=0;i<NUM_CHAR;i++) {
        node->next[i] = NULL;
    }
    node->terminated = false;
    node->text = NULL;

    return node;
}

bool insert_trie_node(trie_node_t **node, char *word) {
    if(*node == NULL) {
        *node = generate_tree_node();
    }

    int length = strlen(word);
    trie_node_t *temp = *node;
    for(int i=0;i<length;i++) {
        if(temp->next[(int)(word[i]-'a')] == NULL) {
            temp->next[(int)(word[i]-'a')] = generate_tree_node();
        }
        temp = temp->next[(int)(word[i]-'a')];
    }

    if(temp->terminated) {
        // inserted
        return false;
    }
    temp->terminated = true;
    temp->text = word;
    return true;

}

int cmpfunc(const void* a, const void*b){
    return(strcmp(*(const char**)a, *(const char**)b));
}

void help(trie_node_t *node, char ***result, int i_res, int *i_col, char *searchword, int i_search, int n_search) {
    if(node->terminated && i_search >= n_search) {
        if(*i_col < 3) {
            // printf("%s\n", node->text);
            result[i_res][(*i_col)++] = node->text;
        }
        else {
            return;
        }
    }

    for(int i=0;i<NUM_CHAR;i++) {
        if(node->next[i] != NULL) {
            if(i_search >= n_search || (int)(searchword[i_search]-'a') == i) {
                help(node->next[i], result, i_res, i_col, searchword, i_search+1, n_search);
            }

        }
    }
}


char ***suggestedProducts(char **products, int productsSize, char *searchWord, int *returnSize, int **returnColumnSizes) {
    // qsort(products, productsSize, sizeof(const char*), cmpfunc);
    int search_len = strlen(searchWord);
    *returnSize = search_len;

    char ***result = malloc(search_len*sizeof(char **));
    for(int i=0;i<search_len;i++) {
        result[i] = malloc(3*sizeof(char *));
        memset(result[i], 0, 3*sizeof(char *));
    }
    int *return_col = malloc(search_len*sizeof(int));
    memset(return_col, 0, search_len*sizeof(int));
    *returnColumnSizes = return_col;


    trie_node_t *root = NULL;
    for(int i=0;i<productsSize;i++) {
        (void)insert_trie_node(&root, products[i]);
    }

    for(int i=0;i<search_len;i++) {
        help(root, result, i, &return_col[i], searchWord, 0, i+1);
    }

    return result;
}
