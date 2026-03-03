class Solution {
    string invert(string s){
        for(int i=0;i<s.size();i++){
            s[i]=(s[i]=='0')?'1':'0';
        }
        return s;
    }
    string f(string s,int n){
        if(n==0)    return s;
        string a=s;
        string i=invert(s);
        reverse(i.begin(),i.end());
        return f(a+"1"+i,n-1);
    }
public:
    char findKthBit(int n, int k) {
        string s=f("0",n);
        return s[k-1];
    }
};