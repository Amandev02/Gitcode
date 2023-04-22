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
    int maxi = INT_MIN;
    int pathsum(TreeNode* root){
        if(!root) return 0;
        int ls = max(0,pathsum(root->left));
        int rs = max(0,pathsum(root->right));
        maxi = max(maxi, ls+rs+root->val);
        return root->val+max(ls,rs);
    }
    int maxPathSum(TreeNode* root) {
        pathsum(root);
        return maxi;
    }
};