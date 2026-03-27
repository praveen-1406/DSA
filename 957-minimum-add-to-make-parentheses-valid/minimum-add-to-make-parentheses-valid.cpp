class Solution {
public:
    int minAddToMakeValid(string s) {
        int lp=0, rp=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')   lp++;
            else{
                if(lp>0)    lp--;
                else rp++;
            }
        }
        
        return rp+lp;
    }
};