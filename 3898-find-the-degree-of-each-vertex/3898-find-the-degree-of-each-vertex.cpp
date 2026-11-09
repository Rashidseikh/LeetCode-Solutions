class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
      int m = matrix[0].size();
        vector<vector<int>>adj(n);

      

      for(int i = 0; i<n; i++){
         for(int j = 0; j<m; j++){
             if(matrix[i][j]==1){
                adj[i].push_back(j);
              }
            }
       }
        vector<int>ans;
        for(int i = 0; i<n;i++){
            ans.push_back(adj[i].size());
        }
        return ans;
    }
};