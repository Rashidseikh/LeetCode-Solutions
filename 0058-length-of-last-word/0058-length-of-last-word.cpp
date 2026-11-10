class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int i = n-1;
        while(i>=0 && s[i]==' '){
            i--;
        }
        int k = 0;
         while(i>=0 && s[i] !=' '){
            i--;
            k++;
        }
        return k;
    }
};