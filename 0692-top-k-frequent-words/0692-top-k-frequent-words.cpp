class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>ans;
        unordered_map<string,int>m;
        
        for(auto x : words){
            m[x]++;
        }
        vector<pair<string,int>>freqList(m.begin(),m.end());
        sort(freqList.begin(),freqList.end(),[](pair<string,int>&a,pair<string,int>&b){
            if(a.second == b.second){
                return a.first < b.first;
            }
            return a.second > b.second;
        });
        for(int i =0; i<k; i++){
            ans.push_back(freqList[i].first);
        }
        
        return ans;
    }
};