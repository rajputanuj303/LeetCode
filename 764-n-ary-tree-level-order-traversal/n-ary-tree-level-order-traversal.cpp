/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};

        queue<Node*> que;
        que.push(root);

        vector<vector<int>> res;

        while(!que.empty()){

            int size = que.size();
            vector<int> temp;

            while(size--){
                Node* curr = que.front();
                temp.push_back(curr->val);
                que.pop();

                for(Node* ch : curr->children){
                    que.push(ch);
                }
            }
            res.push_back(temp);
        }
        
        return res;
    }
};