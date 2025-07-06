class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // vector<int>change={0,0,0};
        int five=0,ten=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                five++;
            }
            else if(bills[i]==10){
                if(five>=1){
                    five-=1;
                    ten++;
                }else   return false;
                
            }
            else{
                if(ten>=1 && five>=1){
                    ten-=1;
                    five-=1;
                }else if(five>=3){
                    five-=3;
                }else   return false;
            }
        }
        return true;
    }
};