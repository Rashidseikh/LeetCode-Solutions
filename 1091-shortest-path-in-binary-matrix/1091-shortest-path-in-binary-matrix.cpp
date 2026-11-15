class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) {
            return -1;
        }
        vector<vector<int>>vis(n,vector<int>(n,0));
        q.push({0,0});
        vis[0][0]= 1;
        
        while(!q.empty()){
            auto [r,c] = q.front();
            int current_dist = vis[r][c];
            q.pop();
            if (r == n - 1 && c == n - 1) {
                return current_dist;
            }
            for(int delRow = -1; delRow <=1;delRow++){
                for(int delCol = -1; delCol<=1;delCol++){
                    if (delRow == 0 && delCol == 0) continue;
                       int nr = r + delRow;
                       int nc = c + delCol;
                       if(nr >=0 && nr < n && nc>=0 && nc <n && grid[nr][nc]==0 && vis[nr][nc] ==0){
                         vis[nr][nc] = current_dist+1 ;
                         q.push({nr,nc});
                       }
                }
            }
        }
        return -1;
    }
};