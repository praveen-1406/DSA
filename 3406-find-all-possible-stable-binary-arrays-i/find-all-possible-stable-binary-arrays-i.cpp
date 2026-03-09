class Solution {
    int MOD=1e9+7;
    int t[201][201][2];
public:
    
    int f(int z,int o,int lastOne,int limit){
        if(z==0 && o==0)    return 1;
        if(t[z][o][lastOne]!=-1)    return t[z][o][lastOne];

        int result=0;
        if(lastOne){
            for(int len=1;len<=min(z,limit);len++){
                result=(result+f(z-len,o,0,limit))%MOD;
            }
        }
        else{
            for(int len=1;len<=min(o,limit);len++){
                result=(result+f(z,o-len,1,limit))%MOD;
            }
        }
        return t[z][o][lastOne]= result;
        
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t,-1,sizeof(t));
        int startOne=f(one,zero,true,limit);
        int startZero=f(one,zero,false,limit);

        return (startOne+startZero)%MOD;
    }
};