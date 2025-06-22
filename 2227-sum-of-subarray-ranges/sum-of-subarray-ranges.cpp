class Solution {
public:
    vector<int>findNGE(vector<int>&arr){
        stack<int>st;
        int n=arr.size();
        vector<int>nge(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            nge[i]=(st.empty())?n:st.top();
            st.push(i);
        }
        return nge;
    }
    vector<int>findNSE(vector<int>&arr){
        stack<int>st;
        int n=arr.size();
        vector<int>nse(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i]=(st.empty())?n:st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int>findPGE(vector<int>&arr){
        stack<int>st;
        int n=arr.size();
        vector<int>pge(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            pge[i]=(st.empty())?-1:st.top();
            st.push(i);
        }
        return pge;
    }
    vector<int>findPSE(vector<int>&arr){
        stack<int>st;
        int n=arr.size();
        vector<int>pse(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            pse[i]=(st.empty())?-1:st.top();
            st.push(i);
        }
        return pse;
    }
    
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int>nse=findNSE(nums);
        vector<int>nge=findNGE(nums);
        vector<int>pse=findPSE(nums);
        vector<int>pge=findPGE(nums);

        long long largest=0,smallest=0;
        for(int i=0;i<n;i++){
            int sleft=i-pse[i],sright=nse[i]-i;
            int gleft=i-pge[i],gright=nge[i]-i;
            smallest+=1LL*sleft*sright*nums[i];
            largest+=1LL*gleft*gright*nums[i];
        }
        return largest-smallest;
    }
};

