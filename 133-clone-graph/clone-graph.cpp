/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> visited;
    Node* cloneGraph(Node* node) {

        if(node == nullptr) return nullptr;

        if(visited.count(node)) return visited[node];

        Node* curr = new Node(node->val, {});
        visited[node] = curr;

        for(Node* neigh : node->neighbors){

            if(visited.count(neigh)){
                curr->neighbors.push_back(visited[neigh]);
                continue;
            }
            Node* next = cloneGraph(neigh);
            curr->neighbors.push_back(next);
        }

        return curr;
    }
};