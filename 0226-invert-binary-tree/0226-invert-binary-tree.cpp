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
void fxn(TreeNode* root){
    if(root==NULL){
        return;
    }
    fxn(root->left);
    fxn(root->right);
    TreeNode * l=root->left;
    root->left=root->right;
     root->right=l;
    return;
}
    TreeNode* invertTree(TreeNode* root) {
        fxn(root);
        return root;
    }
};