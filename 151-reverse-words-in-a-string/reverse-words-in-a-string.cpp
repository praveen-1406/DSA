class Solution {
    void reverse(int i,int j,string &s){
        while(i<j){
            swap(s[i++],s[j--]);
        }
    }
public:
    string reverseWords(string s) {
        string temp="";
        int n = s.size();
        int i=0;
        while(i<n){
            while(i<n && s[i]==' ')     i++;
            if(i>=n)    break;
            if(!temp.empty())   temp+=' ';
            while(i<n && s[i]!=' ')     temp+=s[i++];
        }
        s=temp;
        reverse(0,s.size()-1,s);
        int l=0;
        for(int r=0;r<=s.size();r++){
            if(r==s.size()||s[r]==' '){
                reverse(l,r-1,s);
                l=r+1;
            }
        }
        return s;
    }
};