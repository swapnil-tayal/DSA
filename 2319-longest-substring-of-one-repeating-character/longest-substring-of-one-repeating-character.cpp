struct Node {
    int len;
    int prefix, suffix, best;
    char leftChar, rightChar;

    Node() : len(0), prefix(0), suffix(0), best(0),
             leftChar(0), rightChar(0) {}

    Node(char c) : len(1), prefix(1), suffix(1), best(1),
                   leftChar(c), rightChar(c) {}
};

class SegmentTree {
    vector<Node> tree;
    string s;
    int n;

    Node merge(Node a, Node b) {
        
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;
        res.len = a.len + b.len;
        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.prefix = a.prefix;
        res.suffix = b.suffix;
        res.best = max(a.best, b.best);

        if (a.rightChar == b.leftChar) {
            res.best = max(res.best, a.suffix + b.prefix);
            if (a.prefix == a.len) res.prefix = a.len + b.prefix;
            if (b.suffix == b.len) res.suffix = b.len + a.suffix;
        }
        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = Node(s[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {

        if (l == r) {
            tree[node] = Node(c);
            return;
        }

        int mid = (l + r) / 2;
        if (idx <= mid) update(2 * node, l, mid, idx, c);
        else update(2 * node + 1, mid + 1, r, idx, c);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    SegmentTree(string str) {
        s = str;
        n = s.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    void update(int idx, char c) {
        update(1, 0, n - 1, idx, c);
    }

    int longestSameSubstring() {
        return tree[1].best;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {

        SegmentTree st(s);
        vector<int> ans;
        int n = queryCharacters.size();
        for(int i=0; i<n; i++){
            st.update(queryIndices[i], queryCharacters[i]);
            ans.push_back(st.longestSameSubstring());
        }
        return ans; 
    }
};