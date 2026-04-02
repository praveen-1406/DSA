class Solution {
public:
vector<string>ans;
    vector<string> addOperators(string s, int target) {
        helper(s,target,0,"",0,0);
        return ans;
    }
    void helper(string s,int target,int i,const string & path, long eval,long residual){
        if(i==s.length()){
            if(eval==target){
                ans.push_back(path);
            }
                return;
        }
            string curStr;
            long num=0;
            for(int j=i;j<s.length();j++){
                //handle 0s
                if(j>i && s[i]=='0')    return;  // 0*8+.. valid but *08+.. not valid number, must be a operator in between
                curStr+=s[j];
                num=num*10+s[j]-'0';
                if(i==0){
                    helper(s,target,j+1,path+curStr,num,num);
                }else{
                    helper(s,target,j+1,path+"+"+curStr,eval+num,num);
                    helper(s,target,j+1,path+"-"+curStr,eval-num,-num);
                    helper(s,target,j+1,path+"*"+curStr,(eval-residual)+residual*num,residual*num);
                }


            }
    }
};