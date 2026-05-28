const int MAXN = 500001; // total chars in wordsContainer ≤ 5×10^5

int ch[MAXN][26];
int bestSize[MAXN];
int bestIdx[MAXN];
int cnt;

void init() {
    cnt = 1; // 0 = root
    memset(ch[0], -1, sizeof(ch[0]));
    bestSize[0] = INT_MAX;
    bestIdx[0]  = INT_MAX;
}

int newNode() {
    memset(ch[cnt], -1, sizeof(ch[cnt]));
    bestSize[cnt] = INT_MAX;
    bestIdx[cnt]  = INT_MAX;
    return cnt++;
}

void insert(string& word, int index) {
    int node = 0;
    int sz = word.size();
    for (char c : word) {
        int k = c - 'a';
        if (ch[node][k] == -1) ch[node][k] = newNode();
        node = ch[node][k];
        if (sz < bestSize[node] || (sz == bestSize[node] && index < bestIdx[node])) {
            bestSize[node] = sz;
            bestIdx[node]  = index;
        }
    }
}

int query(string& word) {
    int node = 0, index = INT_MAX;
    for (char c : word) {
        int k = c - 'a';
        if (ch[node][k] == -1) break;
        node = ch[node][k];
        index = bestIdx[node];
    }
    return index;
}

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        init();
        int minIndex = 0;

        for (int i = 0; i < (int)wordsContainer.size(); i++) {
            reverse(wordsContainer[i].begin(), wordsContainer[i].end());
            if (wordsContainer[i].size() < wordsContainer[minIndex].size())
                minIndex = i;
            insert(wordsContainer[i], i);
        }

        vector<int> ans;
        for (auto& q : wordsQuery) {
            reverse(q.begin(), q.end());
            int res = query(q);
            ans.push_back(res == INT_MAX ? minIndex : res);
        }
        return ans;
    }
};