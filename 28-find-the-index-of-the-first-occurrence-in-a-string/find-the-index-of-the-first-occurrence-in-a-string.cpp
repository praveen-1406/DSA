class Solution {
    void computeLPSArray(string &pat,int M,vector<int>&lps){
        int len=0;
        int i=1;
        while(i<M){
            if(pat[i]==pat[len]){
                len++;
                lps[i]=len;
                i++;
            }else{
                if(len!=0){
                    len=lps[len-1];
                }else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
public:
    int strStr(string haystack, string needle) {
        int N=haystack.length();
        int M=needle.length();
        vector<int>result;
        vector<int>lps(M,0);
        computeLPSArray(needle,M,lps);
        int i=0;
        int j=0;
        while(i<N){
            if(haystack[i]==needle[j]){
                i++;
                j++;
            }
            if(j==M){
                return (i-j);
                // j=lps(j-1);
            }else if(haystack[i]!=needle[j]){
                if(j!=0)    j=lps[j-1];
                else    i++;
            }
        }
        return -1;
    }
};