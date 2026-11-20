class Solution {
public:
int ans = 0;
  void bfs(vector<vector<int>>& grid, int k,vector<vector<int>>&vis,int sum,int row,int col){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});
        vis[row][col]= 1;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        while(!q.empty()){
            auto it = q.front();
            int r = it.first;
            int c = it.second;

            q.pop();
            for(int i = 0; i<4;i++){
                int nr = r + delRow[i];
                int nc = c + delCol[i];
                if(nr>=0 && nr <n && nc>=0 && nc < m && !vis[nr][nc] && grid[nr][nc] != 0){
                    q.push({nr,nc});
                    sum += grid[nr][nc];
                    vis[nr][nc]= 1;
                }
            }
        }
        if(sum % k==0){
        ans++;
        sum = 0;
        }
  }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0; i<n;i++){
            for(int j = 0; j<m;j++){
                if(!vis[i][j]&& grid[i][j]>0){
                    bfs(grid,k,vis,grid[i][j],i,j);
                }
            }
        }
      return ans;
    }
};