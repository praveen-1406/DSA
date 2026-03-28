#include<string>
class Solution {
    long long power(long long base,long long exp,long long M){
        long long result=1;
        while(exp>0){
            if(exp&1)   result=(result*base)%M;
            base=(base*base)%M;
            exp>>=1;
        }
        return result;
    }
public:
    int repeatedStringMatch(string a, string b) {
        // int q=(b.size()+a.size()-1)/a.size();  //ceil
        // string s="";
        // for(int i=0;i<q;i++){
        //     s+=a;
        // }
        // if(s.find(b)!=string::npos)  return q;
        // s+=a;
        // if(s.find(b)!=string::npos)  return q+1;
        // return -1;
        auto check=[&](int index){
            for(int i=0;i<b.size();i++){
                if(a[(i+index)%a.size()]!=b[i]) return false;
            }
            return true;
        };
        int q=(b.size()-1)/a.size()+1;
        long long p=113, M=1e9+7;
        long long pInv=power(p,M-2,M);
        long long powerVal=1;

        long long bHash= 0;
        for(int i=0;i<b.size();i++){
            bHash= (bHash+powerVal*b[i])%M;
            powerVal=(powerVal*p)%M;
        }

        powerVal=1;
        
        long long aHash=0;
        for(int i=0;i<b.size();i++){
            aHash=(aHash+powerVal*a[(i)%a.size()])%M;
            powerVal=(powerVal*p)%M;
        }

        if(aHash==bHash && check(0))    return q;

        powerVal=(powerVal*pInv)%M;   //p^(n-1)

        for(int i=b.size();i<(q+1)*a.size();i++){
            aHash=(aHash-a[(i-b.size())%a.size()]+M)%M;
            aHash=(aHash*pInv)%M;

            aHash=(aHash+a[i%a.size()]*powerVal)%M;

            if(aHash==bHash && check(i-b.size()+1)){
                return (i<q*a.size())?q:q+1;
            }
        }
        return -1;

    }
};














