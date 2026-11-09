class Solution {
public:
    bool dfs(int r, int c, int pr, int pc, vector<vector<char>>& grid, char target, vector<vector<int>>& vis) {
        vis[r][c] = 1;
        int n = grid.size();
        int m = grid[0].size();
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (nr >= 0 && nc >= 0 && nr < n && nc < m && target == grid[nr][nc]) {
                if (nr == pr && nc == pc) continue; // Skip parent cell
                
                if (vis[nr][nc]) return true; // Cycle found!
                
                if (dfs(nr, nc, r, c, grid, target, vis)) return true;
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    if (dfs(i, j, -1, -1, grid, grid[i][j], vis)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};