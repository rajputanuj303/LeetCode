class Solution {
public:
    struct Node {
        int pre = 0;        // longest same-letter run starting at the left edge
        int suf = 0;        // longest same-letter run ending at the right edge
        int maxLen = 0;     // longest same-letter run anywhere inside
        int size = 0;
        char leftChar = 0;  // letter at the left edge
        char rightChar = 0; // letter at the right edge
    };

    int n;
    vector<Node> tree; //segmen tree size 4*n

    void merge(int i) {

        Node L = tree[2*i+1];
        Node R = tree[2*i+2];

        Node res;

        res.size = L.size + R.size;
        res.leftChar  = L.leftChar;
        res.rightChar = R.rightChar;

        res.pre = L.pre;
        if (L.pre == L.size && L.rightChar == R.leftChar) {
            res.pre = L.pre + R.pre;
        }

        res.suf = R.suf;
        if (R.suf == R.size && L.rightChar == R.leftChar) {
            res.suf = R.suf + L.suf;
        }

        res.maxLen = max(L.maxLen, R.maxLen);
        if (L.rightChar == R.leftChar) {
            res.maxLen = max(res.maxLen, L.suf + R.pre);
        }

        tree[i] = res;
    }

    void buildSegmentTree(int i, int l, int r, string& s) {
        if (l == r) {
            tree[i] = { 1, 1, 1, 1, s[l], s[l] };
            return;
        }
        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, s);
        buildSegmentTree(2 * i + 2, mid + 1, r, s);
        merge(i);
    }

    void update(int i, int l, int r, int pos, char ch) {
        if (l == r) { //l == r == pos
            tree[i] = { 1, 1, 1, 1, ch, ch };
            return;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid) {
            update(2 * i + 1, l, mid, pos, ch);
        } else {
            update(2 * i + 2, mid + 1, r, pos, ch);
        }
        merge(i);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        n = s.size();
        tree.assign(4 * n, Node()); //segment tree size 4*n

        buildSegmentTree(0, 0, n - 1, s);

        int k = queryIndices.size();

        vector<int> result(k);
        for (int i = 0; i < k; i++) {
            int pos = queryIndices[i];
            char ch = queryCharacters[i];
            update(0, 0, n - 1, pos, ch);
            result[i] = tree[0].maxLen; //root node covers entire string
        }

        return result;
    }
};