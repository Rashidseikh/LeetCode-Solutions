class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>ans;
        unordered_map<int,int>m;
        int n = A.size();
        
        for(int i = 0; i < n; i++){
           m[A[i]]++;
           m[B[i]]++;
           int cnt = 0;
           for(int j =0; j<=i;j++){
            if(m[A[j]]==2){
                    cnt++;
                }
            }
               ans.push_back(cnt);
           
        }
        return ans;
    }
};