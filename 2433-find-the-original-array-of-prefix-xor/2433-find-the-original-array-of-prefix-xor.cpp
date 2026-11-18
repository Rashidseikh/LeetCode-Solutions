class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int>ans;
        int sum = pref[0];
        ans.push_back(sum);
        int n = pref.size();
        for(int i = 1; i<n;i++){
            sum = sum ^ pref[i];

            ans.push_back(sum);
            sum = sum^pref[i-1];
        }
        return ans;
    }
};