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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        if(!root) return {};        

        queue<TreeNode*> que;
        que.push(root);

        vector<vector<int>> res;

        while(!que.empty()){

            int size = que.size();

            vector<int> temp;

            while(size--){
                TreeNode* curr = que.front();
                temp.push_back(curr->val);
                que.pop();

                if(curr->left) que.push(curr->left);
                if(curr->right) que.push(curr->right);
            }

            res.push_back(temp);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};