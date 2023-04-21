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
     
    // void preorder(TreeNode* root){
    //     if(root==nullptr) return;
    //     pre.push_back(root->val);
    //     preorder(root->left);
    //     preorder(root->right);
    // }
    
    vector<int> preorderTraversal(TreeNode* root) {
        
       stack<TreeNode*> qu;
        vector<int> pre;
         if(root==NULL) return pre;
        
        qu.push(root);
        while(!qu.empty()){
            TreeNode* t = qu.top();
            qu.pop();
          pre.push_back(t->val);
          if(t->right!=nullptr)  qu.push(t->right);
          if(t->left!=nullptr) qu.push(t->left); 
             
        }
        return pre;
    }
};