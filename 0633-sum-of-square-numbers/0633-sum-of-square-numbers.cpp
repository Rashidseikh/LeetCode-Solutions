class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long i = 0; i*i<=c;i++){
          double dig = sqrt(c - i*i);
          if(floor(dig) == dig){
            return true;
          }
        }
        return false;
    }
};