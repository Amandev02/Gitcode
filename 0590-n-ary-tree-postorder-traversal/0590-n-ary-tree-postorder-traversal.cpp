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
    vector<int> post;
    void postor(Node* root){
        if(root==nullptr) return;
       for(auto &it:root->children)  postor(it);
        post.push_back(root->val);
    }
    
    vector<int> postorder(Node* root) {
        postor(root);
        return post;
        
    }
};