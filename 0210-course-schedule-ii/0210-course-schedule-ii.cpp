class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses);
        vector<vector<int>>adj(numCourses);
        for(auto it :prerequisites ){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
         int n = numCourses;
       
        queue<int>q;
        for(int i = 0; i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
         vector<int>ans;
         while(!q.empty()){
            int node = q.front();
            q.pop(); 
            ans.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }

         }
         return ans.size()==n ? ans : vector<int>();
    }
};