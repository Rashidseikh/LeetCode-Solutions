class Solution {
public:
int ans = 0;


void dfs(vector<int>& nums,int x,vector<int>&vis,int cnt){
    if( vis[x]) return;
    vis[x]= 1;
    ans = max(ans,cnt);
    dfs(nums,nums[x],vis,cnt+1);
}
    int arrayNesting(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>vis(n,0);
        for(int i = 0; i<n;i++){
            dfs(nums,nums[i],vis,1);
        }
        
        return ans;
    }
};