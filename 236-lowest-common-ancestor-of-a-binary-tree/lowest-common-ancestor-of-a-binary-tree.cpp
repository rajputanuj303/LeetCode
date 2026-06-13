class Solution {
public:
    TreeNode* ans = nullptr;

    int dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return 0;

        int cnt = dfs(root->left, p, q) +
                  dfs(root->right, p, q);

        if (root == p) cnt++;
        if (root == q) cnt++;

        if (cnt == 2 && !ans)
            ans = root;

        return cnt;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ans = nullptr;

        int found = dfs(root, p, q);

        return found == 2 ? ans : nullptr;
    }
};