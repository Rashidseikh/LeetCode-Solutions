class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int n1 = nums1.size();
         int n2 = nums2.size();
       if(n1 < n2) intersect(nums2,nums1);
       unordered_map<int,int>m;
       for(int i = 0; i<n1;i++){
        m[nums1[i]]++;
       }
       for(int x : nums2){
         if(m[x]>0){
            ans.push_back(x);
            m[x]--;
         }
       }
       return ans;
    }
};