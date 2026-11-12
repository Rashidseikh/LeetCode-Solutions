class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans1 = 1,ans2 = 1;
        for(int i = 0;i<n;i++){
             int cnt1 = 1;
            for(int j = i;j<n-1;j++){
                if(nums[j+1]>nums[j]) cnt1++;
                else break;
            }
            ans1 = max(ans1,cnt1);
        }
        for(int i = 0;i<n;i++){
            int cnt2 = 1;
            for(int j = i;j<n-1;j++){
                if(nums[j+1]<nums[j]) cnt2++;
                else break;
            }
            ans2 = max(ans2,cnt2);
        }
        return ans1 >= ans2 ? ans1 : ans2;
    }
};