class Solution {
public:
    pair<int, int> dfs(TreeNode* root){
        if(!root) return {0, INT_MIN};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int cMax = max({root->val, left.second, right.second});
        int dCount = left.first + right.first;

        if(root->val == cMax)
            dCount++;

        return {dCount, cMax};
    }

    int countDominantNodes(TreeNode* root) {
        return dfs(root).first;
    }
};