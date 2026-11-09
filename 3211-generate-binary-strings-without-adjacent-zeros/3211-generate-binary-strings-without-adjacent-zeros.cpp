class Solution {
public:
void helper(int n,string &temp,vector<string>& ans ){
  if(n==temp.length()){
    ans.push_back(temp);
    return;
  }
 temp.push_back('1');
 helper(n,temp,ans);
 temp.pop_back();
 if(temp.empty() || temp.back() != '0'){
    temp.push_back('0');
    helper(n,temp,ans);
    temp.pop_back();
 }
}
    vector<string> validStrings(int n) {
        string temp="";
        vector<string>ans;
        helper(n,temp,ans);
        return ans;
    }
};