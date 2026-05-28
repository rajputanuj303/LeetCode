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
    TreeNode* Solver(TreeNode* root, int low, int high){

        if(!root) return nullptr;
        
        if(root->val < low){
            return Solver(root->right, low, high);
        }

        if(root->val > high){
            return Solver(root->left, low, high);
        }

        root->left = Solver(root->left, low, high);
        root->right = Solver(root->right, low, high);

        return root;
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return Solver(root, low, high);
    }
};