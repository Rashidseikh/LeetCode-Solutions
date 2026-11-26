class Solution {
public:
int ans = 1;
void bfs(vector<vector<int>>& matrix,int row,int col,vector<vector<int>>&best){
     queue<pair<int,pair<int,int>>>q;
     q.push({1,{row,col}});
     best[row][col] = max(best[row][col], 1);

     int n = matrix.size();
     int m = matrix[0].size();
    //  vector<int>vis(n,vector<int>(m,0));
    //  vis[row][col] = 1;
     int count = 0;
     int delRow[] = {-1,0,1,0};
     int delCol[] = {0,1,0,-1};
     while(!q.empty()){
        auto it = q.front();
        q.pop();
        int r = it.second.first;
        int c = it.second.second;
        int cnt = it.first;
        if (cnt < best[r][c]) continue;
        count = max(count,cnt);
        for(int i = 0; i<4; i++){
            int nr = r + delRow[i];
            int nc = c + delCol[i];
            if(nr >=0 && nr <n && nc >=0 && nc <m && matrix[nr][nc]> matrix[r][c] ){
                int nextCnt = cnt + 1;
                
                if (nextCnt > best[nr][nc]) {
                        best[nr][nc] = nextCnt;
                        q.push({nextCnt, {nr, nc}});
                    }
            }
        }
     }
     ans = max(ans,count);
}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
         int n = matrix.size();
         int m = matrix[0].size();
         vector<vector<int>> best(n, vector<int>(m, 0));
           for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                bfs(matrix,i,j,best);
            }
           }
           return ans;
    }
};