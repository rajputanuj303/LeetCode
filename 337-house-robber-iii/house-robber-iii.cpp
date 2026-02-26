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
    
    int robMax(TreeNode* root, unordered_map<TreeNode*, int> &dp){
        if(!root) return 0;

        if(dp.find(root) != dp.end()) return dp[root];

        // take 
        int take = root->val;
        if(root->left) take += robMax(root->left->left, dp) + robMax(root->left->right, dp);
        if(root->right) take += robMax(root->right->left, dp) + robMax(root->right->right, dp);

        // not take
        int nottake = 0 + robMax(root->left, dp) + robMax(root->right, dp);


        return dp[root] = max(take, nottake);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        return robMax(root, dp);
    }
};