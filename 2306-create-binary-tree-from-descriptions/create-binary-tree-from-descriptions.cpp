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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        unordered_map<int, TreeNode*> mpp;
        int rootVal = 0;

        for(vector<int> &v : descriptions){
            int parentVal = v[0];
            int childVal = v[1];
            bool isLeft = v[2];

            rootVal ^= childVal;

            if(!mpp.count(parentVal)){
                TreeNode* parent = new TreeNode(parentVal);
                mpp[parentVal] = parent;
                rootVal ^= parentVal;
            }

            if(!mpp.count(childVal)){
                TreeNode* child = new TreeNode(childVal);
                mpp[childVal] = child;
                rootVal ^= childVal;
            }

            

            if(isLeft){
                mpp[parentVal]->left = mpp[childVal];
            }else{
                mpp[parentVal]->right = mpp[childVal];
            }

        }

        // cout << rootVal << endl;

        return mpp[rootVal];
    }
};