class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        int i = 0;
        int n = path.length();
        string ans = "";
        while(i<n){
            string temp = "";
            while (i < n && path[i] == '/') {
                i++;
            }
            if (i >= n) break;
            while(i < n && path[i] != '/'){
                temp += path[i];
                i++;
            }
            
            if(temp == ".." ) {
                if(!st.empty()){
                    st.pop_back();
                }
            } else if(temp != "."){
             st.push_back(temp);
            }
             
        }
        for(auto x : st){
            ans += '/' +x;
        }
        return ans.empty() ? "/" : ans;;
    }
};