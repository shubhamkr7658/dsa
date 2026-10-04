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
string solve(TreeNode * root,vector<TreeNode*>&vec,unordered_map<string,int>&mp){
    if(root==NULL){
        return "NULL";
    }
    string s=to_string(root->val)+","+solve(root->left,vec,mp)+","+solve(root->right,vec,mp);
    if(mp[s]==1){
        vec.push_back(root);
    }
        mp[s]++;
    
    return s;
}
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>vec;
        unordered_map<string,int>mp;
        solve(root,vec,mp);
        return vec;
    }
};