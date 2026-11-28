
class Solution {
public:
    class DisjointSet {
    public:
        vector<int> size, parent;

        DisjointSet(int n) {
            size.resize(n + 1, 1);
            parent.resize(n + 1);

            for(int i = 0; i <= n; i++)
                parent[i] = i;
        }

        int findUPar(int node) {
            if(node == parent[node])
                return node;

            return parent[node] = findUPar(parent[node]);
        }

        void unionBySize(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if(ulp_u == ulp_v) return;

            if(size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    };

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        DisjointSet ds(n * n);

        // Step 1: Connect all adjacent 1s
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 0) continue;

                for(int k = 0; k < 4; k++) {
                    int nr = i + delRow[k];
                    int nc = j + delCol[k];

                    if(nr >= 0 && nr < n &&
                       nc >= 0 && nc < n &&
                       grid[nr][nc] == 1) {

                        int nodeNo = i * n + j;
                        int adjNode = nr * n + nc;

                        ds.unionBySize(nodeNo, adjNode);
                    }
                }
            }
        }

        // Step 2: Find largest existing island
        int ans = 0;

        for(int r = 0; r < n; r++) {
            for(int c = 0; c < n; c++) {
                if(grid[r][c] == 1) {
                    int root = ds.findUPar(r * n + c);
                    ans = max(ans, ds.size[root]);
                }
            }
        }

        // Step 3: Try converting every 0 into 1
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 0) {
                    int cnt = 1;

                    unordered_set<int> uniqueParents;

                    for(int k = 0; k < 4; k++) {
                        int nr = i + delRow[k];
                        int nc = j + delCol[k];

                        if(nr >= 0 && nr < n &&
                           nc >= 0 && nc < n &&
                           grid[nr][nc] == 1) {

                            int adjNode = nr * n + nc;
                            uniqueParents.insert(ds.findUPar(adjNode));
                        }
                    }

                    for(auto x : uniqueParents) {
                        cnt += ds.size[x];
                    }

                    ans = max(ans, cnt);
                }
            }
        }

        return ans == 0 ? 1 : ans;
    }
};
