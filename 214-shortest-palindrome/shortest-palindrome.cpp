class Solution {
public:
    void computeLPS(string pat,vector<int>&lps){
        int M=pat.size();
        int len=0;
        lps[0]=0;
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
    string shortestPalindrome(string s) {
        int n=s.length();
        string rev=s;
        reverse(rev.begin(),rev.end());
        // for(int i=0;i<n;i++){
        //     if(! memcmp(s.c_str(),rev.c_str()+i,n-i)){
        //         return rev.substr(0,i)+s;
        //     }
        // }
        // return rev+s;

        string temp=s+'-'+rev;
        vector<int>lps(temp.length(),0);
        computeLPS(temp,lps);
        int longLpsLen=lps[temp.length()-1];
        string culprit=rev.substr(0,n-longLpsLen);
        return culprit+s;
    }
};