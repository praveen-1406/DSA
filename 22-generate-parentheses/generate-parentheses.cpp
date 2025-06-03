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
            func(v,open-1,close,x);

            if(open<close){
                y+=")";
                func(v,open,close-1,y);
            }
        }
    }


    vector<string> generateParenthesis(int n) {
        vector<string>v;
        func(v,n,n,"");
        return v;
    }
};