class Solution {
public:
void merge(vector<int>& nums,int l ,int mid, int h){
    int i = l, j = mid+1;
    vector<int>ans;
    while(i <= mid && j <= h){
          if(nums[i]<=nums[j]){
            ans.push_back(nums[i++]);
          }else{
            ans.push_back(nums[j++]);
          }
    }
    while(i<=mid){
        ans.push_back(nums[i++]);
    }
     while(j<=h){
        ans.push_back(nums[j++]);
    }
    for(int i = 0; i<ans.size();i++){
        nums[i+l] = ans[i];
    }
}
   void mergeSort(vector<int>& nums,int l ,int h){
    if(l>=h) return;
        int mid = l +(h -l)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,h);
        merge(nums,l,mid,h);
   }
    vector<int> sortArray(vector<int>& nums) {
      
       mergeSort(nums,0,nums.size()-1);
       return nums;
    }
};