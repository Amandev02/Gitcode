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

//     void post(TreeNode* root, vector<int> &res){
//       if(root==nullptr) return;
//         post(root->left,res);
//         post(root->right,res);
//         res.push_back(root->val);
        
//     }
    vector<int> postorderTraversal(TreeNode* root) {
       
        stack<TreeNode*> st;
        vector<int> res;
         if(root==nullptr) return res;
       st.push(root);
        while(!st.empty()){
            TreeNode* t = st.top();
            st.pop();
            res.push_back(t->val);
            if(t->left!=nullptr) st.push(t->left);
            if(t->right!=nullptr) st.push(t->right);
            
        }
        reverse(res.begin(),res.end());
        return res;
    }
};