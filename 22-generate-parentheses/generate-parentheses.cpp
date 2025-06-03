class Solution {
public:

    void func(vector<string>&v,int open,int close,string s){
        if(open==0){
            while(close){
                s+=")";
                close--;
            }
            v.push_back(s);
            return;
        }

        if(open){
            string x=s,y=s;

            x+="(";
            int o=open-1;
            func(v,o,close,x);

            if(open<close){
                y+=")";
                int c=close-1;
                func(v,open,c,y);
            }
        }
    }


    vector<string> generateParenthesis(int n) {
        vector<string>v;
        func(v,n,n,"");
        return v;
    }
};