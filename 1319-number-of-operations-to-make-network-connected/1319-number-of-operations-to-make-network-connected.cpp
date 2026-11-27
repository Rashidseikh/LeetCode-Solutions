class Solution {
public:
class DisjointSet{
      vector<int>size,parent;
      public:
      DisjointSet(int n){
          size.resize(n+1,1);
          parent.resize(n+1);
          for(int i = 0; i<n;i++) parent[i] = i;
          }
      int findUPar(int node){
          if(node == parent[node]) return node;
          
          return findUPar(parent[node]);
      }
      
      void unionBySize(int u,int v){
          int ulp_u = findUPar(u);
          int ulp_v = findUPar(v);
          if(ulp_u == ulp_v) return;
          if(size[ulp_u]<size[ulp_v]){
              parent[ulp_u] = ulp_v;
              size[ulp_v] += size[ulp_u];
          }else{
              parent[ulp_v] = ulp_u;
              size[ulp_u] += size[ulp_v];
          }
      }
  };
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < static_cast<size_t>(n - 1)) {
    return -1;
}
        DisjointSet ds(n);
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            if(ds.findUPar(u) != ds.findUPar(v)){
                ds.unionBySize(u,v);
            }
        } 
       int cnt = 0;
        for(int i = 0; i <n; i++){
            if(ds.findUPar(i) == i){
                cnt++;
            }
        }
        return cnt-1;
    }
};