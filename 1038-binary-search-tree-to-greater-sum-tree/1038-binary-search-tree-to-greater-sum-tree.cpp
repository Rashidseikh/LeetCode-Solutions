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
int child = 0;
void helper(TreeNode* root){
    if(!root) return;
    helper(root->right);
    child += root->val;
    root->val = child;
    helper(root->left);
}
    TreeNode* bstToGst(TreeNode* root) {
        helper(root);
        return root;
        
    }
};