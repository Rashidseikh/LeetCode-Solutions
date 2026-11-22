class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
       
        vector<vector<pair<long long,long long>>>adj(n);
        for(auto x : roads){
             adj[x[0]].push_back({x[1],x[2]});
             adj[x[1]].push_back({x[0],x[2]});
        }
        priority_queue<pair<long long,long long>,
        vector<pair<long long,long long>>,
        greater<pair<long long,long long>>>pq;
        vector<long long>dist(n,LLONG_MAX);
        pq.push({0,0});
        dist[0] = 0;
      
        long long mod = 1e9 +7;
        vector<long long>ways(n,0);
        ways[0] = 1;
        while(!pq.empty()){
            auto it = pq.top();
            long long wt = it.first;
            long long node = it.second;
            pq.pop();
            for(auto it : adj[node]){
                long long v = it.first;
                long long nweight = it.second;
                if (wt + nweight < dist[v]) {
                    dist[v] = wt + nweight;
                    ways[v] = ways[node];
                    pq.push({dist[v], v});
                }
                else if(wt + nweight == dist[v]){
                      ways[v] = (ways[v] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};