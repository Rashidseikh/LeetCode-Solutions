class Solution {
public:
    bool canAliceWin(int n) {
        if(n <10) return false;
        int cnt = 0;
        for(int i = 10; i>=1; i--){
            if(n-i>=0) cnt++;
         
            else break;
               n = n-i;
        }
        return  cnt % 2 == 1; 
    }
};