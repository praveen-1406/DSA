class Solution {
    int MOD=1e9+7;
    
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
        vector<vector<vector<int>>>t(zero+1,vector<vector<int>>(one+1,vector<int>(2,0)));
        t[0][0][0]=t[0][0][1]=1;    //t[z][o][lastOne]

        for(int i=0;i<=min(zero,limit);i++){
            t[i][0][0]=1;
        }
        for(int j=0;j<=min(one,limit);j++){
            t[0][j][1]=1;
        }

        for(int z=0;z<=zero;z++){
            for(int o=0;o<=one;o++){
                if(z==0 || o==0)    continue;
                
                    t[z][o][1]=(t[z][o-1][1]+t[z][o-1][0])%MOD;
                    if(o-1>=limit){
                        t[z][o][1]=(t[z][o][1]-t[z][o-1-limit][0] + MOD)%MOD;
                    }


                    t[z][o][0]=(t[z-1][o][1]+t[z-1][o][0])%MOD;
                    if(z-1>=limit){
                        t[z][o][0]=(t[z][o][0]-t[z-1-limit][o][1] + MOD)%MOD;
                    }
            }
        }
        
        return (t[zero][one][0]+t[zero][one][1])%MOD;
    }
};