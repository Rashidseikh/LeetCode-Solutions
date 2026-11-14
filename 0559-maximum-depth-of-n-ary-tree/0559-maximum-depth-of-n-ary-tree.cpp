/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
int ans = 0;
void dfs(Node* root,int cnt){
    if(!root) return;
    ans = max(ans,cnt);
    for(auto child : root->children){
    dfs(child,cnt+1);
    }

}
    int maxDepth(Node* root) {
        dfs(root,1);
       return ans; 
    }
};