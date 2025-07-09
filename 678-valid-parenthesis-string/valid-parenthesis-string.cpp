class Solution {
public:
    bool checkValidString(string s) {
        int l=0,r=0,a=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')   l++;
            else if(s[i]==')')   r++;
            else   a++;

            if(l+a>=r)  continue;
            else    return false;
        }
        l=0,r=0,a=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='(')   l++;
            else if(s[i]==')')   r++;
            else   a++;

            if(r+a>=l)  continue;
            else    return false;
        }

        return true;
    }
};