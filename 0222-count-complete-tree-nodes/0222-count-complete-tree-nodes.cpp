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
int findleft(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    return 1+findleft(root->left);
}
int findright(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    return 1+findright(root->right);
}
int solve(TreeNode* root){
    int a=findleft(root);
    int b=findright(root);
    if(a==b){
        return (1<<a)-1;
    }
    return 1+solve(root->left)+solve(root->right);
}
    int countNodes(TreeNode* root) {
       return solve(root); 
    }
};