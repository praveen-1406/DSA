class Solution {
public:

    // void func(vector<string>&v,int open,int close,string s){
    //     if(open==0){
    //         while(close){
    //             s+=")";
    //             close--;
    //         }
    //         v.push_back(s);
    //         return;
    //     }

    //     if(open){
    //         string x=s,y=s;

    //         x+="(";
    //         func(v,open-1,close,x);

    //         if(open<close){
    //             y+=")";
    //             func(v,open,close-1,y);
    //         }
    //     }
    // }

    void backtrack(vector<string>& res, string s, int open, int close) {
    if (open == 0 && close == 0) {
        res.push_back(s);
        return;
    }

    if (open > 0)
        backtrack(res, s + "(", open - 1, close);

    if (close > open)
        backtrack(res, s + ")", open, close - 1);
    }


    vector<string> generateParenthesis(int n) {
        vector<string>v;
        // func(v,n,n,"");
        backtrack(v,"",n,n);
        return v;
    }
};