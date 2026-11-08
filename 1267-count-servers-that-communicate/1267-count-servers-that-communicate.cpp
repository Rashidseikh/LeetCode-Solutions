class Solution {
public:
int ans = 0;

void dfs(int row, int col,vector<vector<int>>& grid, vector<vector<int>>&vis){
    
     int n = grid.size();
     int m = grid[0].size();
     for(int i = 0; i<n;i++){
        if(i == row) continue;
        if(grid[i][col]==1 && !vis[i][col]) {
          ans++;
          vis[i][col] = 1;
        }
           
     }
     for(int j =0 ;j<m ; j++){
        if(j==col) continue;
        if(grid[row][j]==1&&!vis[row][j]) {
            vis[row][j] = 1;
            ans++;
        }
     }
   
   
}
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        
       vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                   dfs(i,j,grid,vis);
                }
            }
        }
        return ans;
    }
};