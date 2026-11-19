class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n <=3 ) return 0;
       int x = nums[n-1] - nums[2];
       int y = min(nums[n-2]-nums[1],x);
       int z = min(nums[n-3]-nums[0],y);
        
        return z;
    }
};