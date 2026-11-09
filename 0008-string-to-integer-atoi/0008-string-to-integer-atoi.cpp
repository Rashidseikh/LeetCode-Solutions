class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int i = 0; 
        int n = s.length();
       
       while(i<n && s[i]==' '){
        i++;
       }
       while(i<n && s[i]=='_'){
        i++;
       }
       if (i == n) return 0;
       if(s[i] == '+'){
        sign = 1;
        i++;
       }else if (s[i]=='-'){
        sign = -1;
        i++;
       }
     

      long long sum = 0;
     
       while(i <n && isdigit(s[i])){
           int rem = s[i] -'0';
           sum = sum *10 + rem; 
           if (sign == 1 && sum > INT_MAX) {
              return INT_MAX;
           }
            if (sign == -1 && -sum < INT_MIN) {
                 return INT_MIN;
                }
                i++;
       }
      
      return sum*sign;
    }
};