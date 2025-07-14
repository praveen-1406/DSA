class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        
        vector<int>left(n);
        left[0]=1;
        // right[n-1]=1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1])   left[i]=left[i-1]+1;
            else    left[i]=1;

            // if(ratings[n-1-i]>ratings[n-i])     right[n-1-i]=right[n-i]+1;
            // else    right[n-1-i]=1;
        }
        int sum=max(1,left[n-1]),cur=1;
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                cur++;
                // right=cur;
            }else   cur=1;
            sum+=max(cur,left[i]);
        }
        return sum;
    }
};