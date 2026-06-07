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
        unordered_set<int> stt;

        for(vector<int> &v : descriptions){
            int parentVal = v[0];
            int childVal = v[1];
            bool isLeft = v[2];

            TreeNode* parent = nullptr;
            TreeNode* child = nullptr;

            if(mpp.count(parentVal)){
                parent = mpp[parentVal];
            }else{
                parent = new TreeNode(parentVal);
                mpp[parentVal] = parent;
            }

            if(mpp.count(childVal)){
                child = mpp[childVal];
            }else{
                child = new TreeNode(childVal);
                mpp[childVal] = child;
            }
            stt.insert(childVal);

            if(isLeft){
                parent->left = child;
            }else{
                parent->right = child;
            }

            // cout << parent->val << " " << child->val << endl;
        }

        TreeNode* root = nullptr;

        for(vector<int> &v : descriptions){
            int parentVal = v[0];
            if(!stt.count(parentVal)){
                root = mpp[parentVal];
                break;
            }
        }

        return root;
    }
};