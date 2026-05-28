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
    int idx, n;
    pair<int, int> parsed(string traversal){
        int countdashes = 0;
        while(idx < n && traversal[idx] == '-'){
            countdashes++;
            idx++;
        }

        string num;
        while(idx < n && traversal[idx] != '-'){
            num += traversal[idx];
            idx++;
        }

        return {stoi(num), countdashes};
    }
    TreeNode* Solver(int dashes, string traversal){

        if(idx >= n) return nullptr;

        int prevIdx = idx;

        auto [val, countdashes] = parsed(traversal);

        TreeNode* root = nullptr;
        
        if (countdashes != dashes) {
            idx = prevIdx;   // restore index
            return nullptr;
        }

        root = new TreeNode(val);

        root->left = Solver(dashes+1, traversal);
        root->right = Solver(dashes+1, traversal);

        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        n = traversal.size();
        idx = 0;
        return Solver(0, traversal);
    }
};