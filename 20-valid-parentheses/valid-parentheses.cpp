class Solution {
public:
    bool isValid(string s) {
        stack<char>par;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='[' )    par.push(s[i]);
            else    {
                if(s[i]==')' && par.size()>0 && par.top()=='(')     par.pop();
                else if(s[i]=='}' && par.size()>0 && par.top()=='{')     par.pop();
                else if(s[i]==']' && par.size()>0 && par.top()=='[')     par.pop();
                else    return false;
            }
            
        }
        if(par.size()==0)   return true;
        else    return false;
    }
};