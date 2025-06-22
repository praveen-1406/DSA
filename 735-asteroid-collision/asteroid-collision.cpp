class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // stack<int>st;
        vector<int>st;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            bool f=1;
            while(!st.empty() && (st.back()>0 && asteroids[i]<0)){
                if(abs(st.back())>abs(asteroids[i])) {
                    f=0;
                    break;
                }
                else if(abs(st.back())==abs(asteroids[i])){
                    f=0;
                    st.pop_back();
                    break;
                }
                st.pop_back();
            }
            if(f)   st.push_back(asteroids[i]);
        }
        // vector<int>ans(st.size());
        // for(int i=st.size()-1;i>=0;i--){
        //     ans[i]=st.top();
        //     st.pop();
        // }
        return st;
    }
};