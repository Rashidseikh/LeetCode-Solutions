class Solution {
public:
    static bool comp(pair<int,int>&a,pair<int,int>&b){
        return a.first<b.first;
    }
    vector<vector<int>> groupThePeople(vector<int>& nums) {
        int n =nums.size();
        vector<vector<int>>ans;
       vector<pair<int,int>>temp;
       for(int i=0; i<n;i++){
        temp.push_back({nums[i],i});
       }
        sort(temp.begin(),temp.end());
        vector<int>curr;
        
        for(auto x : temp){
            curr.push_back(x.second);
            if(curr.size()==x.first){
                ans.push_back(curr);
                curr.clear();
            }
           
        }
      
        return ans;
    }
};