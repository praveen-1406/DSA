class Solution {
public:
    bool hasAlternatingBits(int n) {
        int i=31;
        for(i;i>=0;i--){
            int bit=(((1<<i)&n)==0)?0:1;
            if(bit==1)    break;
        }
        bool isOne=1;
        for(i;i>=0;i--){
            int bit=(((1<<i)&n)==0)?0:1;
            if(bit!=isOne)  return false;
            isOne=!isOne;
        }
        return true;
    }
};