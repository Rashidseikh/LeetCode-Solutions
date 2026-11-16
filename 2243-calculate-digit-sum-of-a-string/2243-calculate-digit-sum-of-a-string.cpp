class Solution {
public:
 int digitSum(string s){
    int sum = 0;
    int i = 0;
    while(i<s.length()){
        int dig = s[i]-'0';
        sum += dig;
        i++;
    }
    return sum;
 }
    string digitSum(string s, int k) {
       
        while(s.length()>k){
             int i = 0;
        string ans = "";
            while(i<s.length()){
                int dig = digitSum(s.substr(i,k));
                ans += to_string(dig);
                 i = i+ k;
            }
            s = ans; 
        }
        return s;
    }
};