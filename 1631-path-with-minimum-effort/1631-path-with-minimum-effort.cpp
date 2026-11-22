class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        int n  = heights.size();
        int m = heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        pq.push({0,{0,0}});
        dist[0][0] = 0;
       
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        while(!pq.empty()){
            auto it = pq.top();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
            pq.pop();
            if(r == n-1 && c == m-1) return diff;
            for(int i= 0; i<4; i++){
                int nr = r + delRow[i];
                int nc = c + delCol[i];
                if(nr >=0 && nr < n & nc>=0 && nc < m){
                    int newEffort = max(abs(heights[nr][nc]-heights[r][c]),diff);
                    if(newEffort < dist[nr][nc]){
                        pq.push({newEffort,{nr,nc}});
                         dist[nr][nc] = newEffort;
                    }
                }
            }
        }

        return 0;
    }
};