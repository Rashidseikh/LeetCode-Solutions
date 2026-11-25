class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<int>dist(n+1,INT_MAX);
    vector<vector<pair<int,int>>>adj(n+1);
    for(auto it : times){
        adj[it[0]].push_back({it[1],it[2]});
    }
      priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>>pq;
        pq.push({0,k});
        dist[k] = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int time = it.first;
            for(auto it : adj[node]){
                int v = it.first;
                int t = it.second;
                if(time + t < dist[v] ){
                    dist[v] = time + t;
                    pq.push({dist[v],v});
                }
            }
        }
        int ans = -1;
         for(int i = 1; i<=n; i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(dist[i],ans);
         }
        
        return ans;
    }
};