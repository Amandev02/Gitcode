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
   
//     void inorder(TreeNode* root, vector<int> &res){
//       if(root==nullptr) return;
//         inorder(root->left,res);
//         res.push_back(root->val);
//         inorder(root->right,res);
        
//     }
    vector<int> inorderTraversal(TreeNode* root) {
       stack<TreeNode*> qu;
        vector<int> res;
        TreeNode* node = root;
       
        while(true){
             if(node!=nullptr){
                 qu.push(node);
                 node = node->left;
             }
            else{
                if(qu.empty()) break;
                node = qu.top();
                qu.pop();
                res.push_back(node->val);
                node= node->right;
            }
             
        }
        return res;
    }
};