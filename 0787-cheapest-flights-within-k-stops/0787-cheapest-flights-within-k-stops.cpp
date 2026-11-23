class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         vector<vector<pair<int,int>>>adj(n);
         for(auto x : flights){
            adj[x[0]].push_back({x[1],x[2]});
         }
       queue<pair<int,pair<int,int>>>q;
        
        vector<int>dist(n,INT_MAX);
        // {price,{node,stopes}}
        q.push({0,{src,0}});
        dist[src] = 0;
        int price = 0;
        while(!q.empty()){
            auto it = q.front();
            int node = it.second.first;
            int step = it.second.second;
             price = it.first;
            q.pop();
            if (step > k) continue;
           
            for(auto it : adj[node]){
                int v = it.first;
                int prices = it.second;
                if(prices + price < dist[v]){
                    dist[v] = prices + price;
                    q.push({dist[v],{v,step+1}});
                }


            }
        }
       return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};