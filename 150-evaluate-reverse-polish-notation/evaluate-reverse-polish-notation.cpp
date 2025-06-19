#include<cctype>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto it:tokens){
            
            if(it=="+"||it=="-"||it=="/"||it=="*"){
                int t1=st.top();
                st.pop();
                int t2=st.top();
                st.pop();
                int eval;
                if(it=="+") eval=t2+t1;
                if(it=="-") eval=t2-t1;
                if(it=="/") eval=t2/t1;
                if(it=="*") eval=t2*t1;
                st.push(eval);
            }else{
                st.push(stoi(it));
            }
        }
        return st.top();
    }
};