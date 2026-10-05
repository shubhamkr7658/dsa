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
unordered_map<int,int>mp;
int mx=INT_MIN;
int dfs(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int sum=root->val+dfs(root->left)+dfs(root->right);
    int frq=++mp[sum];
    mx=max(frq,mx);
    return sum;

}
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int>ans;
        for(auto &t:mp){
            int p=t.first;
            int v=t.second;
            if(mx==v){
                ans.push_back(p);
            }
        }

   return ans;
    }
};