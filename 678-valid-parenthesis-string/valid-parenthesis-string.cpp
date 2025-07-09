class Solution {
public:

    bool f(string s,int ind,int cnt){
        if(cnt<0)   return false;
        if(ind==s.size())   return cnt==0;

        if(s[ind]=='(')     return f(s,ind+1,cnt+1);
        else if(s[ind]==')')   return f(s,ind+1,cnt-1);
        else  return (f(s,ind+1,cnt+1)||f(s,ind+1,cnt-1)||f(s,ind+1,cnt));
    }

    bool checkValidString(string s) {
        // int l=0,r=0,a=0;
        // for(int i=0;i<s.size();i++){
        //     if(s[i]=='(')   l++;
        //     else if(s[i]==')')   r++;
        //     else   a++;

        //     if(l+a>=r)  continue;
        //     else    return false;
        // }
        // l=0,r=0,a=0;
        // for(int i=s.size()-1;i>=0;i--){
        //     if(s[i]=='(')   l++;
        //     else if(s[i]==')')   r++;
        //     else   a++;

        //     if(r+a>=l)  continue;
        //     else    return false;
        // }

        // return true;


//Using recursion
        // return f(s,0,0);

//Using ranges
        int min=0,max=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                min++;
                max++;
            }else if(s[i]==')'){
                min--;
                max--;
            }else{
                min--;
                max++;
            }

            if(min<0)   min=0;
            if(max<0)   return false;   //edge case, s="("
        }
        return min==0;

    }
};