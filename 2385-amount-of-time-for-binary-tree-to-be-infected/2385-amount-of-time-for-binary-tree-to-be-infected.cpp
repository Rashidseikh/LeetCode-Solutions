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
void dfs(TreeNode* root, unordered_map<int,vector<int>>&adj){
    if(!root)  return;
    TreeNode* curr = root;
    if(curr->left){
        adj[curr->val].push_back(curr->left->val);
         adj[curr->left->val].push_back(curr->val);
        dfs(curr->left,adj);
    }
     if(curr->right){
        adj[curr->val].push_back(curr->right->val);
        adj[curr->right->val].push_back(curr->val);
        dfs(curr->right,adj);
    }
}

    int amountOfTime(TreeNode* root, int start) {
       unordered_map<int,vector<int>>adj;
        dfs(root,adj);
        queue<pair<int,int>>q;
        unordered_set<int>vis;
        q.push({start,0});
        vis.insert(start);
        int tm = -1;
        while(!q.empty()){
            int node = q.front().first;
            int d = q.front().second;
            q.pop();
            tm = max(tm,d);
            for(auto it : adj[node]){
                if(!vis.count(it)){
                    vis.insert(it);
                 q.push({it,d+1});
                }
                
            }
        }
        return tm;
    }
};