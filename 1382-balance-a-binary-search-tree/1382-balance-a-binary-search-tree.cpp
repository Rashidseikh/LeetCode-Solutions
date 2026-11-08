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
    void helper(TreeNode* root, vector<int>&inorder){
           if(!root) return;
           helper(root->left,inorder);
           inorder.push_back(root->val);
           helper(root->right,inorder);

    }
   TreeNode* build(vector<int>&inorder,int i,int j){
    if(i > j) return NULL;
    int mid = i +(j -  i)/2;
    TreeNode* root = new TreeNode(inorder[mid]);
    root->left = build(inorder,i,mid-1);
    root->right = build(inorder,mid+1,j);
    return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        helper(root,inorder);
        return build(inorder,0,inorder.size()-1);

    }
};