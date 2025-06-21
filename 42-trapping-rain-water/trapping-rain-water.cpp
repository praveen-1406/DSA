class Solution {
public:
    int trap(vector<int>& height) {
        int h=0;
        int cap=0;
        int w=0;
        int x=0;
        stack<pair<int,int>>st;
        for(int i=0;i<height.size();i++){
            if(st.empty() || height[i]<st.top().first){
                st.push({height[i],i});
            }
            else{
                while(!st.empty() && height[i]>=st.top().first){
                    w=i-(st.top().second+1);
                    x=min(st.top().first,height[i])*w-h*w;
                    cap+=x;
                    h=st.top().first;
                    st.pop();
                }
                if(!st.empty()){
                    w=i-(st.top().second+1);
                    x=min(st.top().first,height[i])*w-h*w;
                    cap+=x;
                    h=st.top().first;
                    // st.pop();
                }
                st.push({height[i],i});
            }
            h=0;
            
        }
        return cap;
    }
};