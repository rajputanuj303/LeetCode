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
    pair<int, int> Solver(TreeNode* root, int &count){
        if(!root) return {0, 0};

        pair<int, int> left = Solver(root->left, count);
        pair<int, int> right = Solver(root->right, count);

        int sum = left.first + right.first + root->val;
        int noOfNodes = left.second + right.second + 1;

        if(sum/noOfNodes == root->val) count++;
        return {sum, noOfNodes};
    }
    int averageOfSubtree(TreeNode* root) {

        int count = 0;
        Solver(root, count);
        return count;
    }
};