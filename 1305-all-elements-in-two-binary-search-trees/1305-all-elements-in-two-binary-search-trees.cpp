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
vector<int>ans;
void helper1(TreeNode* root1){
    if(!root1) return;
    helper1(root1->left);
    ans.push_back(root1->val);
 
    helper1(root1->right);

}
void helper2(TreeNode* root2){
    if(!root2 ) return;
    helper2(root2->left);
    ans.push_back(root2->val);
 
    helper2(root2->right);

}

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        helper1(root1);
        helper2(root2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};