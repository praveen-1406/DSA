#include<string>
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int q=(b.size()+a.size()-1)/a.size();  //ceil
        string s="";
        for(int i=0;i<q;i++){
            s+=a;
        }
        if(s.find(b)!=string::npos)  return q;
        s+=a;
        if(s.find(b)!=string::npos)  return q+1;
        return -1;
    }
};