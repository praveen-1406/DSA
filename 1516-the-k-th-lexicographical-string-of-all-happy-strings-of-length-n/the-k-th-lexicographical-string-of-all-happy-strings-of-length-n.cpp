class Solution {
    string f(int n,string s,int &k){
        if(n==0){
            k--;
            if(k==0)    return s;
            return "";
        }

        vector<char>v={'a','b','c'};
        int size=s.size();
        string ans="";
        for(int i=0;i<3;i++){
            if(s[size-1]!=v[i])     ans=f(n-1,s+v[i],k);
            if(ans.size())  return ans;
        }
        return "";
    }
public:
    string getHappyString(int n, int k) {
        int x=3*(1<<(n-1));
        if(k>x)     return "";
        // vector<string>hstring;
        string a=f(n-1,"a",k);
        string b=f(n-1,"b",k);
        string c=f(n-1,"c",k);
        // sort(hstring.begin(),hstring.end());
        // return hstring[k-1];
        if(a.size())   return a;
        else if(b.size())  return b;
        else return c;
    }
};