class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            int f=1;
            while(!st.empty() && ((st.top()>0 && asteroids[i]<0))){
                if(abs(st.top())>abs(asteroids[i])) {
                    f=0;
                    break;
                }
                else if(abs(st.top())==abs(asteroids[i])){
                    f=0;
                    st.pop();
                    break;
                }
                st.pop();
            }
            if(f)   st.push(asteroids[i]);
        }
        vector<int>ans(st.size());
        for(int i=st.size()-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};