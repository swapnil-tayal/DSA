char* removeDuplicateLetters(char* s) {
    int n = strlen(s);

    int mp[26] = {0};
    for (int i = 0; i < n; i++) {
        mp[s[i] - 'a'] = i;
    }

    char* result = (char*)malloc(sizeof(char) * (n + 1));
    int vis[26] = {0};
    int resultIndex = 0;

    for (int i = 0; i < n; i++) {
        if (vis[s[i] - 'a']) {
            continue;
        }

        if (resultIndex == 0 || result[resultIndex - 1] < s[i]) {
            result[resultIndex++] = s[i];
            vis[s[i] - 'a'] = 1;
        } else {
            while (resultIndex > 0 && result[resultIndex - 1] > s[i] && mp[result[resultIndex - 1] - 'a'] > i) {
                vis[result[--resultIndex] - 'a'] = 0;
            }
            result[resultIndex++] = s[i];
            vis[s[i] - 'a'] = 1;
        }
    }

    result[resultIndex] = '\0';

    return result;
}