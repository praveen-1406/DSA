class Solution {
    
public:
    string addBinary(string a, string b) {
        int i=a.size()-1,j=b.size()-1;
        int sum=0,carry=0;
        string ans="";
        while(i>=0 && j>=0){
            sum=carry+(a[i]-'0')+(b[j]-'0');
            ans+=(sum%2==1)?'1':'0';
            carry=sum/2;
            i--;
            j--;
        }
        while(i>=0){
            sum=carry+(a[i]-'0');
            ans+=(sum%2==1)?'1':'0';
            carry=sum/2;
            i--;
        }
        while(j>=0){
            sum=carry+(b[j]-'0');
            ans+=(sum%2==1)?'1':'0';
            carry=sum/2;
            j--;
        }
        if(carry)   ans+='1';
        reverse(ans.begin(),ans.end());
        return ans;
    } 
};