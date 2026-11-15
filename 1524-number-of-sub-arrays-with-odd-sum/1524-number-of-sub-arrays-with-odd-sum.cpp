class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        
        
        long long mod = 1e9 + 7;
        long long ans = 0;
        long long odd = 0;
        long long even = 1;
        long long sum = 0;
        for(int x : arr){
           sum += x;
           if(sum % 2 != 0){
            ans = (ans + even) %mod;
            odd++;
           }else{
            ans = (ans + odd) % mod;
            even++;
           }
        }
         
        
       
        return ans;
    }
};