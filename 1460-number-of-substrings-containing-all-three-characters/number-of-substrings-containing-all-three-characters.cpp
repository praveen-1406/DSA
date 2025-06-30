class Solution {
public:

    int numberOfSubstrings(string s) {
        int cnt=0,n=s.size();
        int a=-1,b=-1,c=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='a')   a=i;
            else if(s[i]=='b')   b=i;
            else   c=i;

            // if(a!=-1 && b!=-1 && c!=-1){
                int mini=min(min(a,b),c);
                cnt+=mini+1;
            // }
        }
        return cnt;
    }
};