class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int sum = INT_MAX;
        int n = nums.size();
        for(int i = 0; i<n;i++){
            int cnt = 0;
            for(int j = i; j<n; j++){
                cnt += nums[j];
                if(j-i +1>=l && j-i+1 <=r){
                    if(cnt > 0){
                         sum = min(sum,cnt);
                    }
                   
                }
            }
        }
        return sum ==INT_MAX ? -1 : sum;
    }
};