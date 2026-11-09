class Solution {
public:
       bool dfsCheck(int node,vector<vector<int>>&adj,vector<int >&vis,vector<int >&pathVis,vector<int >&check){
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfsCheck(it,adj,vis,pathVis,check)){
                    check[node] = 0;
                    return true;
                }
            }
            else if(pathVis[it]){
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] =0;
        return false;
    }
  
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
         int n = graph.size();
        
        vector<int >vis(n,0);
        vector<int >pathVis(n,0);
         vector<int >check(n,0);
          vector<int> ans;
         for(int i = 0; i <n ; i++){
            if(!vis[i]){
                if(dfsCheck(i,graph,vis,pathVis,check)){
                    continue;
                }
                
            }
        }
        for(int i = 0; i<n;i++){
            if(check[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};