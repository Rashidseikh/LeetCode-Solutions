class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,pair<int,int>>>hash;
        for(auto it : points){
            int x = it[0];
            int y = it[1];
            int d = (x*x + y*y);
            hash.push_back({d,{x,y}});
        }
        sort(hash.begin(),hash.end(),[](auto&a,auto&b){
            return a.first<b.first;
        });
        vector<vector<int>>ans;
        for(int i = 0; i<k; i++){
            auto it = hash[i];
          ans.push_back({it.second.first,it.second.second});
        }
        return ans;
    }
};