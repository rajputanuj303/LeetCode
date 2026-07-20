/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int, int> Solver(TreeNode* root){
        if(!root) return {0, INT_MIN};

        pair<int, int> left = Solver(root->left);
        pair<int, int> right = Solver(root->right);

        int cMax = max({root->val, left.second, right.second});
        int dCount = left.first + right.first;

        if(root->val == cMax) dCount++;

        return {dCount, cMax};
    }
    int countDominantNodes(TreeNode* root) {
        pair<int, int> res = Solver(root);
        return res.first;
    }
};