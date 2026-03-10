class Solution {
    int MOD=1e9+7;
    int t[201][201][2];
public:
    
    // int f(int z,int o,int lastOne,int limit){
    //     if(z==0 && o==0)    return 1;
    //     if(t[z][o][lastOne]!=-1)    return t[z][o][lastOne];

    //     int result=0;
    //     if(lastOne){
    //         for(int len=1;len<=min(z,limit);len++){
    //             result=(result+f(z-len,o,0,limit))%MOD;
    //         }
    //     }
    //     else{
    //         for(int len=1;len<=min(o,limit);len++){
    //             result=(result+f(z,o-len,1,limit))%MOD;
    //         }
    //     }
    //     return t[z][o][lastOne]= result;
        
    // }
    int numberOfStableArrays(int zero, int one, int limit) {
        // memset(t,-1,sizeof(t));
        // int startOne=f(one,zero,true,limit);
        // int startZero=f(one,zero,false,limit);

        // return (startOne+startZero)%MOD;

        memset(t,0,sizeof(t));
        t[0][0][0]=t[0][0][1]=1;    //t[z][o][lastOne]

        for(int z=0;z<=zero;z++){
            for(int o=0;o<=one;o++){
                if(z==0 && o==0)    continue;

                int result=0;
                //last 1
                    for(int len=1;len<=min(z,limit);len++){
                        result=(result+t[z-len][o][0])%MOD;
                    }
                    t[z][o][1]=result;

                result=0;
                //last 0
                    for(int len=1;len<=min(o,limit);len++){
                        result=(result+t[z][o-len][1])%MOD;
                    }
                    t[z][o][0]= result;
            }
        }
        
        return (t[zero][one][0]+t[zero][one][1])%MOD;
    }
};